/* TODO
  - Optimize!
    - Size, see http://www.gammon.com.au/progmem
    - Speed (Do I really need to loop through switches etc that often?)
    - https://matt.sh/howto-c
  - Think about using static for some variables, wherever fit.
  - Be more consistent with values indicating NO ACTION. With the scene controllers it's -1, with the switches it's 0 etc. Not good! Configuring this thing is hard enough ;-)
  - Rethink the naming of the switch actions. They aren't very intuitive yet.
*/

/* IDEAS
  - DIFFICULT TO IMPLEMENT and maybe not necessary: Try to handle switches 09 and 10 separately. They shouldn't have to be configured all the time, makes little to no sense, because this code is supposed to work with MY hardware with MY ideas and I definitely want 09 to change the layer and 10 to handle tuner and bpm.
  - Only define sounds in scenes (then rename to "sounds") and implement "parts", where e.g. part 1 uses sound 1, part 2 uses sound 2, part 3 uses sound 1 again etc. Will safe a lot of memory, because each sound only needs to be defined once.
  - Include another mode which doesn't assign blocks, scenes or functions to a switch, but sounds. Those should be displayed using the whole screen. Then there will be 10 characters per sound. Example: #HigainDly#LogainDly#CleanDly #CrazyDly 
    -> A lot of the code needs to be rewritten using many if statements. Could become a dynamic memory issue.
    -> IDEA: Limit the length of scene names to 9, then in Jam mode display the scene names rather than the block names. Done!
  - Maybe it would be better to configure the way the switches work according to what's assigned to them. Less prone to misconfigurations... On the other hand, who will know if an effect should be activated by toggle, momentary, when pushed or pulled?
    -> I guess to do this I'd have to rewrite quite a lot. But the configuration of songs would become smaller in memory. I like the idea!
  - http://www.rngtng.com/2009/05/17/arduino-fade-and-pulse-a-led-with-just-using-a-digitalport (dim LEDs, right now it's implemented using a hack, which is a binary solution ... not too nice!)
  - The menu item "debounce" needs too much memory because of its 51 items. Can this not be done with a loop or something within the menu() function?
    -> See the TODO section, Optimize -> Size. There are ways!
  - Rethink the way debounce is implemented. If you hit a switch very fast leading to a very short time the cirquit is closed on the switch, right now no action is executed. Looks like the debounce function waits for the configured amount of time until the action gets executed. That of course leads to an immense latency!
    - I'd prefer if it fires the action right at first contact, but then, when the contact is lost again and a second contact takes place within the debounce timeout, NO further action should be executed. That makes a lot more sense to me here.
    -> Could I solve this with a parameter "bool switchPressed[numberOfSwitches]", which is set to 1 in the switchesGO() function, and reset in a different function after a given amount of time with the addition that the switch has to be released?
  - Re-implement offset? I personally don't need it, so not the highest priority, but I want to make the code as accessible as possible
  - Add the ability to directly select songs
  - When I hit a "looper record" switch and then a "looper play" switch, the LED of the "looper record" switch should go off.
    -> However when the recording automatically stops, because its maximum time is reached, the LED won't go off. On the other hand I could turn it off based on a timeout which is as long as the maximum recording length of the Ultra. After that it automatically plays back (iirc).
*/

/* BUGS
  - Calling presets with numbers higher than 255 doesn't work right now. Presets are stored in progmem and may need to be called with pgm_read_word, but that didn't work so far... Doesn't really matter, 255 is WAY enough!!!
    - Maybe using #include <avr/pgmspace.h> solves this? Hm, doubt it...
    - I could solve it by NOT storing this data in progmem. It's not much, so this could be an option.
  - When I increase the amount of songs so the program storage space used goes above about 32%, the damn Arduino doesn't launch anymore. WTF?! 32%?!?! That's nothing!
  - Global adjustments by the internal potis don't work. I thought the code reads the value and adjusts the corresponding value upon loading the song. Have to test this. Maybe the bug was introduced by the option to invert potis?
    -> Actually after trying it again it works. Don't know what went wrong the first time and the code hasn't changed since, so I'll leave this here for the time being.
*/

/* POOL FOR SICK AND STUPID IDEAS
  - Implement the ability to assign a switch to toggle between two blocks
  - The Ultra's Looper has no quantize function. What about adding a time-based virtual switch that automatically switches the looper from rec to play etc.?
    -> Doesn't seem to work... It's completely inaccurate, the internal clock of the Arduino isn't precise enough. Maybe use the tempo SysEx for this?! ... Doesn't send often enough...
  - When I select a preset on the Axe, let the controller read the incoming data and switch to the song this preset is assigned to. --> But that stuff is in PROGMEM, so that seems very complicated.
  - Include a menu option "language" to switch between german and english. Not really necessary for me, but could be cool for others
  - I could make this code in charge of everything: Empty preset on the Axe, the controller creates the whole preset with SysEx commands, including tempo (send two tempo CCs in the right interval)
    - If I assign SysEx data to scenes, I could change whole settings in bypassed blocks before they get activated. Endless possibilities for songs when I just step through the parts.
    -> For this I'd need something else than the Mega. E.g. the Arduino Due could do this - faster, more memory.
  - https://forum.fractalaudio.com/threads/using-sysex-to-recall-present-effect-bypass-status-info-available.39161/#post-533974
    -> Tried it, it's really slow! And not reeeeally necessary, so I won't do it for now.
  - The controller could switch sounds automatically. All I'd have to do is to tell it when the song starts.
    - Is the internal clock accurate enough for something like this? -> NO, absolutely not!!!
*/

#include <LiquidCrystal.h>
#include <MIDI.h>
#include <EEPROM.h>
#include "config.h"
#include "menu.h"
#include "eeprom.h"
#include "gigs.h"
#include "axe_ccs.h"
#include "axe_sysex.h"
#include "leds.h"
#include "display.h"
#include "potis.h"
#include "switches.h"
#include "songs.h"
#include "songs_config.h"
#include "callbacks.h"
#include "tuner.h"
#include "init.h"

#include "axe_pcs_functions.h"
#include "songs_functions.h"
#include "display_functions.h"
#include "eeprom_functions.h"
#include "menu_functions.h"
#include "init_functions.h"
#include "switches_functions.h"
#include "potis_functions.h"
#include "tuner_functions.h"
#include "callbacks_functions.h"
#include "leds_functions.h"

//unsigned int speedCounter = 0;
//unsigned long speedCounterTime1 = 0;
//unsigned long speedCounterTime2 = 0;

void setup() {
  lcd.clear();
  lcd.begin(displayWidth, displayHeight);
  first_run();
  read_eeprom();
  MIDI.begin(MIDI_CHANNEL_OMNI);              //Listen to all incoming MIDI channels.
  MIDI.turnThruOff();                         //Don't want to send stuff the Ultra sends right back to the Ultra
  MIDI.setHandleSystemExclusive(handleSysEx); //see callbacks_functions.h
  initial();
  mainScreen();
}

void loop() {
//  speedCounter++; //My Arduino makes ~472 rounds per second, so I have a delay of ~2.1 ms, which I think is absolutely useable :-)
//  speedCounterTime1 = millis();
//  if (speedCounterTime1 >= speedCounterTime2 + 1000) {
//    lcd.setCursor(0, 0);
//    lcd.print(speedCounter);
//    lcd.print(" rounds per second");
//    speedCounterTime2 = speedCounterTime1;
//    speedCounter = 0;
//  }
  MIDI.read(); //Read incoming MIDI-Data.
  tempoLedOff();
  MIDI.read(); //Read it often! If I put this function just once into loop(), the tuner doesn't work reliably anymore.
  tunerOff();
  MIDI.read();
  ledOff();
  MIDI.read();
  switchesGO();
  MIDI.read();
  buttonsGO();
  MIDI.read();
  potisGO();
}

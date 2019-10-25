//This file contains stuff that needs to be globally defined and which has no dependencies to other stuff.

//intro
const char controllerTitle[26] = "handbuilt MIDI controller";
unsigned char lengthOfControllerTitle = 25; //40 is the maximum, because it's the maximum number of characters the display can display
const char controllerSubtitle[20] = "designed by axifist";
unsigned char lengthOfControllerSubtitle = 19; //40 is the maximum, because it's the maximum number of characters the display can display

//display
const unsigned char RS     = 8;
const unsigned char ENABLE = 9;
const unsigned char D4     = 4;
const unsigned char D5     = 5;
const unsigned char D6     = 6;
const unsigned char D7     = 7;

//MIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI); //This is the same as MIDI_CREATE_DEFAULT_INSTANCE(), only Serial is being replaced by Serial1, see https://github.com/FortySevenEffects/arduino_midi_library/blob/master/src/midi_Defs.h#L226. I use serial1, because serial is being used by USB and because the pin is being covered by the display at my prototype.

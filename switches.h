const unsigned char numberOfSwitches = 10;

const unsigned char SWITCH01 = 22;
const unsigned char SWITCH02 = 24;
const unsigned char SWITCH03 = 26;
const unsigned char SWITCH04 = 28;
const unsigned char SWITCH05 = 30;
const unsigned char SWITCH06 = 32;
const unsigned char SWITCH07 = 34;
const unsigned char SWITCH08 = 46;
const unsigned char SWITCH09 = 48;
const unsigned char SWITCH10 = 50;
const unsigned char switches[numberOfSwitches] = {SWITCH01, SWITCH02, SWITCH03, SWITCH04, SWITCH05, SWITCH06, SWITCH07, SWITCH08, SWITCH09, SWITCH10};

//                         0 means no function
//Those first two are known
const unsigned char TOGD = 1; //Toggle when the switch goes Down
const unsigned char TOGU = 2; //Toggle when the switch goes Up
const unsigned char MOMD = 3; //Momentary when the switch goes Down
const unsigned char MOMU = 4; //Momentary when the switch goes Up

//SELect means, that I e.g. select the next song or next scene. That means, that the LED only shows "The selection has been done". Because this happens very fast, I set the LED to low after a short time, even if the switch is still high (SELD) or low (SELU). Especially for SELU this makes total sense and it was the initial idea for this time-based LED.
const unsigned char SELD = 5; //Select when the switch goes Down
const unsigned char SELU = 6; //Select when the switch goes Up

//ACTivate means, that I e.g. activate a scene. When a switch is assigned to e.g. scene 1, the LED should stay on and only go off if another scene gets selected. That's different from the above.
const unsigned char ACTD = 7; //Activate when the switch goes Down
const unsigned char ACTU = 8; //Activate when the switch goes Up

bool switchState[numberOfSwitches];
bool switchStateOld[numberOfSwitches];
unsigned char loopThroughSwitches = 0;
bool switchReading[numberOfSwitches];
unsigned long switchLastDebounceTime[numberOfSwitches];

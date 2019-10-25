const unsigned char numberOfPotis = 8;
const unsigned char numberOfInternalPotis = 4;
const unsigned char numberOfExternalPotis = 4;

const unsigned char POTI01 =  A8;
const unsigned char POTI02 =  A9;
const unsigned char POTI03 = A10;
const unsigned char POTI04 = A11;
const unsigned char POTI05 = A12;
const unsigned char POTI06 = A13;
const unsigned char POTI07 = A14;
const unsigned char POTI08 = A15;

const unsigned char poti[numberOfPotis]                            = {POTI01, POTI02, POTI03, POTI04, POTI05, POTI06, POTI07, POTI08};
const unsigned int potiValueCalibrationMinimumLevel[numberOfPotis] = {     0,      0,      0,      0,      0,      0,      0,      0}; //The Arduino has a 10bit A-D converter, so the potentiometers can get the numbers 0 to
const unsigned int potiValueCalibrationMaximumLevel[numberOfPotis] = {  1020,   1020,   1020,   1020,   1020,   1020,   1020,   1020}; //1023 assigned. Those values here are used to calibrate all potentiometers separately. Make sure the potentiometer reaches the full range from 0 to 127! (the range 0-1023 gets translated to the range of 0-127, which is required by the MIDI protocol)
const unsigned char controllerValueMinimumLevel[numberOfPotis]     = {     0,      0,      0,      0,      0,      0,      0,      0}; //TODO: Making this configurable is questionable, since I always want to go from 0
const unsigned char controllerValueMaximumLevel[numberOfPotis]     = {   127,    127,    127,    127,    127,    127,    127,    127}; //to 127, except if I use the option to send SysEx data (see axe_sysex.h). But this is not implemented now and probably never will be.
unsigned char loopThroughPotis = 0;
unsigned int potiValue[numberOfPotis];
unsigned int potiValueOld[numberOfPotis];
unsigned char controllerValueOld[numberOfPotis];
unsigned char controllerValue[numberOfPotis];

unsigned char potiFunction = 0;

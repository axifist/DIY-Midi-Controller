unsigned char runMode = 1;
const unsigned char runModeMemory = 0;

unsigned char currentGig = 0;
const unsigned char currentGigMemory = 1;

unsigned char ledDimmerValue = 1;
const unsigned char ledDimmerValueMemory = 2;

unsigned char tunerNoteSetting = 0;
const unsigned char tunerNoteSettingMemory = 3;

unsigned char midiChannelEeprom = 0;
const unsigned char midiChannelEepromMemory = 4;
unsigned char midiChannel = midiChannelItems[midiChannelEeprom];

unsigned char debounceTimeOfSwitches = 25;
const unsigned char debounceTimeOfSwitchesMemory = 5;

unsigned char songCounter = 0;
const unsigned char songCounterMemory = 6;

unsigned char percentageOfInitialisation = 0;

unsigned int loopThroughEeprom = 0;
unsigned int memoryLocationOfIndication = EEPROM.length() - 1;
const bool valueOfIndication = 1;

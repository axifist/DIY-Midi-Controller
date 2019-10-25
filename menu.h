//The menu is being started and exited by the select button on the keypad shielt on the prototype and by the left one on the actual controller. The next two buttons on the controller change between menu items, the next two ones change the value. The right button is the reset button by the way.

const unsigned char menuButton              = 0;
const unsigned char menuButtonCategoryLeft  = 1;
const unsigned char menuButtonCategoryRight = 2;
const unsigned char menuButtonValueLeft     = 3;
const unsigned char menuButtonValueRight    = 4;
const unsigned char menuButtonNone          = 5;

const unsigned char menuButtonsPin = A0;

unsigned int menuButtonsReading = 0;

const unsigned char menuDelay = 250; //The menu buttons don't need to be properly debounced, using delay() is good enough for this. I really don't like using delay(), but in this case it's ok and much easier to code

const unsigned char numberOfmenuItems = 6;
const unsigned char sizeOfmenuItems = 15;
const char menuItemsString[numberOfmenuItems][sizeOfmenuItems] = {"mode          ", "gigs          ", "LED brightness", "tuner notes   ", "MIDI channel  ", "debounce time "};
const unsigned char menuItems[numberOfmenuItems]               = { 0              ,  1              ,  2              ,  3              ,  4              , 5               };

const unsigned char numberOfmodeItems = 2;
const unsigned char sizeOfmodeItems = 6;
const char modeItemsString[numberOfmodeItems][sizeOfmodeItems] = {"gigs ", "songs"};
const unsigned char modeItems[numberOfmodeItems]               = { 0     ,  1     }; //data type unsigned char, because more modes will come
// Gigs are defined in gigs.h in the string gigs

const unsigned char numberOfledDimmerValueItems = 2;
const unsigned char sizeOfledDimmerValueItems = 7;
const char ledDimmerValueItemsString[numberOfledDimmerValueItems][sizeOfledDimmerValueItems] = {"dark  ", "bright"};
const bool ledDimmerValueItems[numberOfledDimmerValueItems]                                  = { 0      ,  1      };

const unsigned char numberOftunerNotesItems = 6;
const unsigned char sizeOftunerNotesItems = 11;
const char tunerNotesItemsString[numberOftunerNotesItems][sizeOftunerNotesItems] = {"english b ", "english # ", "deutsch b ", "deutsch # ", "francais b", "francais #"};
const unsigned char tunerNotesItems[numberOftunerNotesItems]                     = { 0          ,  1          ,  2          ,  3          , 4           , 5               };

const unsigned char numberOfmidiChannelItems = 16;
const unsigned char sizeOfmidiChannelItems = 3;
const char midiChannelItemsString[numberOfmidiChannelItems][sizeOfmidiChannelItems] = {" 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "11", "12", "13", "14", "15", "16"};
const unsigned char midiChannelItems[numberOfmidiChannelItems]                      = {  1 ,   2 ,   3 ,   4 ,   5 ,   6 ,   7 ,   8 ,   9 ,  10 ,  11 ,  12 ,  13 ,  14 ,  15 ,  16 };

const unsigned char numberOfdebounceTimeOfSwitchesItems = 51;
const unsigned char sizeOfdebounceTimeOfSwitchesItems = 6;
const char debounceTimeOfSwitchesItemsString[numberOfdebounceTimeOfSwitchesItems][sizeOfdebounceTimeOfSwitchesItems] = {"off  ", " 1 ms", " 2 ms", " 3 ms", " 4 ms", " 5 ms", " 6 ms", " 7 ms", " 8 ms", " 9 ms", "10 ms", "11 ms", "12 ms", "13 ms", "14 ms", "15 ms", "16 ms", "17 ms", "18 ms", "19 ms", "20 ms", "21 ms", "22 ms", "23 ms", "24 ms", "25 ms", "26 ms", "27 ms", "28 ms", "29 ms", "30 ms", "31 ms", "32 ms", "33 ms", "34 ms", "35 ms", "36 ms", "37 ms", "38 ms", "39 ms", "40 ms", "41 ms", "42 ms", "43 ms", "44 ms", "45 ms", "46 ms", "47 ms", "48 ms", "49 ms", "50 ms"};
const unsigned char debounceTimeOfSwitchesItems[numberOfdebounceTimeOfSwitchesItems]                                 = {  0    ,   1    ,   2    ,   3    ,   4    ,   5    ,   6    ,   7    ,   8    ,   9    ,  10    ,  11    ,  12    ,  13    ,  14    ,  15    ,  16    ,  17    ,  18    ,  19    ,  20    ,  21    ,  22    ,  23    ,  24    ,  25    ,  26    ,  27    ,  28    ,  29    ,  30    ,  31    ,  32    ,  33    ,  34    ,  35    ,  36    ,  37    ,  38    ,  39    ,  40    ,  41    ,  42    ,  43    ,  44    ,  45    ,  46    ,  47    ,  48    ,  49    ,  50    };

bool exitStatusMenu = false; //This is used to get into the while loop and out of it again.
unsigned char menuItem1 = 0;
unsigned char menuItem2 = 0;
unsigned char sizeOfSubmenu = 0;
unsigned char sizeOfSubmenuItems = 0;

unsigned char printSpaces = 0;

const unsigned char numberOfSongs = 2; //Number of songs
const unsigned char numberOfScenes = 20; //Maximum numbers of scenes per song.
const unsigned char numberOfBlocks = 84; //Number of blocks, which can be controlled by scenes
const unsigned char numberOfBlocksPartOne = 22;
const unsigned char numberOfBlocksPartTwo = 21;
const unsigned char numberOfBlocksPartThree = 21;
const unsigned char numberOfBlocksPartFour = 20;
const unsigned char numberOfSongInfos = 2; //1. preset number, 2. number of scenes
const unsigned char numberOfSwitchLayers = 2; //Number of function layers for the switches. 2 is great, then it's a toggle. Starting with 3 it would be circular.
const unsigned char numberOfPotiFunctions = 2;

const unsigned char rangeOfCcs = 99;                             //Official CCs go from 10 to 98, but since we count starting at 0, the range needs to be set to 99 here.
const unsigned char sceneCcOffset = rangeOfCcs - numberOfBlocks; //Now, according to how many of those official CCs are supposed to be controlled by scenes, I need to "move" them. I e.g. don't want the first 5 CCs to be controlled by scenes, the offset is 5 PLUS 10 because the official CCs start at 10.

//const unsigned char NROFSYSEXPARAMS = 8;
//const unsigned char SYSEXLENGTH = 12;

const unsigned char lengthOfSongNames = 12;
const unsigned char lengthOfSceneNames = 10;

const unsigned char gigMode  = 0;
const unsigned char songMode = 1;

unsigned char i = 0; //Used to
unsigned char j = 0; //read song data
unsigned char k = 0; //from PROGMEM

unsigned char m = 0; //Used for the two switch layers

unsigned char currentSong = 0;
unsigned char currentScene = 0;
unsigned char previousScene = 0; //Used, so only blocks whose bypass state changes are being considered.
unsigned char currentBlock = 0;
unsigned char currentPoti = 0;
unsigned char currentSongInfos = 0;
unsigned char currentSwitch = 0;

bool currentSwitchLayer = 0;

char songScenes[numberOfScenes][numberOfBlocks];
char songPotisFunction[numberOfScenes][numberOfPotis][numberOfPotiFunctions];
bool songPotisDirection[numberOfScenes][numberOfPotis][numberOfPotiFunctions];
unsigned char songInfos[numberOfSongInfos];
unsigned char songSwitchesModus[numberOfScenes][numberOfSwitches][numberOfSwitchLayers];
unsigned char songSwitches[numberOfScenes][numberOfSwitches][numberOfSwitchLayers];

char songName[lengthOfSongNames];
char sceneName[numberOfScenes][lengthOfSceneNames];

const char lengthOfBlockNames = 5;
//                                            switch is off  increment scene   decrement scene   increment song   decrement song   toggle function layer   empty   empty   empty   empty   input volume   output 1 volume   output 2 volume   bypass the Axe   tempo   tuner   external 1   external 2   external 3   external 4   external 5   external 6   external 7   external 8   looper 1 record   looper 1 play   looper 1 once   looper 1 stack   looper 1 reverse   looper 2 record   looper 2 play   looper 2 once   looper 2 stack   looper 2 reverse   global bypass   volume increment   volume decrement   amp 1   amp 2   cab 1   cab 2   chorus 1   chorus 2   compressor 1   compressor 2   crossover 1   crossover 2   delay 1   delay 2   drive 1   drive 2   enhancer   filter 1   filter 2   filter 3   filter 4   flanger 1   flanger 2   formant   fx loop   gate 1   gate 2   graphical eq 1   graphical eq 2   graphical eq 3   graphical eq 4   multitap delay   multiband compressor 1   multiband compressor 2   multi delay 1   multi delay 2   parametric eq 1   parametric eq 2   parametric eq 3   parametric eq 4   phaser 1   phaser 2   pitch 1   pitch 2   quad chorus 1   quad chorus 2   resonator 1   resonator 2   reverb 1   reverb 2   ring modulator   rotary 1   rotary 2   synth 1   synth 2   tremolo 1   tremolo 2   vocoder   volume 1   volume 2   volume 3   volume 4   wahwah 1   wahwah 2   scene 1   scene 2   scene 3   scene 4   scene 5   scene6   scene 7   scene 8   scene 9   scene10   scene11   scene12   scene13   scene14   scene15   scene16   scene17   scene18   scene19   scene20   scene21   scene22   scene23   scene24
const char blocks[123][lengthOfBlockNames] = {"    ",        "scn+",           "scn-",           "SNG+",          "SNG-",          "Layr",                 "asdf", "asdf", "asdf", "asdf", "IVol",        "Out1",           "Out2",           "Byp ",          "Temp", "Tune", "Ext1",      "Ext2",      "Ext3",      "Ext4",      "Ext5",      "Ext6",      "Ext7",      "Ext8",      "L1Re",           "L1Pl",         "L11x",         "L1St",          "L1Rv",            "L2Re",           "L2Pl",         "L21x",         "L2St",          "L2Rv",            "GlBy",         "VolI",            "VolD",            "Amp1", "Amp2", "Cab1", "Cab2", "Cho1",    "Cho2",    "Cmp1",        "Cmp2",        "Cro1",       "Cro2",       "Dly1",   "Dly2",   "Drv1",   "Drv2",   "Enha",    "Fil1",    "Fil2",    "Fil3",    "Fil4",    "Flg1",     "Flg2",     "Form",   "FxLp",   "Gte1",  "Gte2",  "GEq1",          "GEq2",          "GEq3",          "GEq4",          "MTap",          "MCo1",                  "MCo2",                  "MDl1",         "MDl2",         "PEq1",           "PEq2",           "PEq3",           "PEq4",           "Pha1",    "Pha2",    "Pit1",   "Pit2",   "QCh1",         "QCh2",         "Res1",       "Res2",       "Rev1",    "Rev2",    "Ring",          "Rot1",    "Rot2",    "Syn1",   "Syn2",   "Trm1",     "Trm2",     "Voco",   "Vol1",    "Vol2",    "Vol3",    "Vol4",    "Wah1",    "Wah2",    "Sc01",   "Sc02",   "Sc03",   "Sc04",   "Sc05",   "Sc06",  "Sc07",   "Sc08",   "Sc09",   "Sc10",   "Sc11",   "Sc12",   "Sc13",   "Sc14",   "Sc15",   "Sc16",   "Sc17",   "Sc18",   "Sc19",   "Sc20",   "Sc21",   "Sc22",   "Sc23",   "Sc24",};

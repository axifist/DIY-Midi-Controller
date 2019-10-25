const PROGMEM char songScenesPartTwoProgmem[numberOfSongs][numberOfScenes][numberOfBlocksPartTwo] = { //This is the core of it all and my main reason to build this controller. It's where the scenes get defined. As you can see it's even possible to e.g. start a looper when changing the scenes. Perfect for live performances, because it's a no brainer then!!! 0 means off (bypassed), 127 means on.
  { //Giggleract
    //Blocks
    //Amp1 Amp2 Cab1 Cab2 Cho1 Cho2 Cmp1 Cmp2 Cro1 Cro2 Dly1 Dly2 Drv1 Drv2 Enha Fil1 Fil2 Fil3 Fil4 Flg1 Flg2
    {  127,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {  127,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0, 127, 127,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0, 127, 127,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0, 127, 127,   0,   0,   0, 127,   0,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {  127,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0,   0}
  },
  { //Demo Song für Video
    //Blocks
    //Amp1 Amp2 Cab1 Cab2 Cho1 Cho2 Cmp1 Cmp2 Cro1 Cro2 Dly1 Dly2 Drv1 Drv2 Enha Fil1 Fil2 Fil3 Fil4 Flg1 Flg2
    {  127,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0},
    {  127,   0, 127,   0,   0,   0,   0,   0,   0,   0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0},
    {  127,   0, 127,   0,   0,   0,   0,   0,   0,   0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0},
    {  127,   0, 127,   0,   0,   0,   0,   0,   0,   0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0, 127,   0, 127,   0,   0,   0,   0,   0,   0,   0}
  },
};

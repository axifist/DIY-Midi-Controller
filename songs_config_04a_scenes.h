const PROGMEM char songScenesPartOneProgmem[numberOfSongs][numberOfScenes][numberOfBlocksPartOne] = { //This is the core of it all and my main reason to build this controller. It's where the scenes get defined. As you can see it's even possible to e.g. start a looper when changing the scenes. Perfect for live performances, because it's a no brainer then!!! 0 means off (bypassed), 127 means on.
  { //Giggleract
    //Blocks
    //Tune Ext1 Ext2 Ext3 Ext4 Ext5 Ext6 Ext7 Ext8 L1Re L1Pl L11x L1St L1Rv L2Re L2Pl L21x L2St L2Rv GlBy VolI VolD
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0}
  },
  { //Demo Song für Video
    //Blocks
    //Tune Ext1 Ext2 Ext3 Ext4 Ext5 Ext6 Ext7 Ext8 L1Re L1Pl L11x L1St L1Rv L2Re L2Pl L21x L2St L2Rv GlBy VolI VolD
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  21,   0,   0,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  42,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  63,   0,   0,   0,   0,   0,   0, 127,   0,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  84,   0,   0,   0,   0,   0,   0,   0, 127,   0,   0,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 105,   0,   0,   0,   0,   0,   0,   0,   0,   0, 127,   0,   0,   0},
    {    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 127,   0,   0,   0,   0,   0,   0,   0,   0, 127,   0,   0,   0,   0},
    {  127,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0}
  },
};

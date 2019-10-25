const PROGMEM unsigned char songSwitchesProgmem[numberOfSongs][numberOfScenes][numberOfSwitches][numberOfSwitchLayers] = { //Here I define, what's assigned to which switch for both Layrtion Layrs FOR EVERY SCENE!!! Layr 1 is the default, Layr 2 can be filled with other Layrtions in case the 8 buttons on my controller aren't sufficient. So in total I can assign 16 Layrtions. Switch 9 and 10 will always be the same for me. You can do whatever you want to do with them ;-)
  { //Giggleract
    //Switch01,     Switch02,     Switch03,     Switch04,     Switch05,     Switch06,     Switch07,     Switch08,     Switch09,     Switch10
    //Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2
    {{scnp,    0}, {scnm,    0}, {Dly1,    0}, {   0,    0}, {SNGp,    0}, {SNGm,    0}, {Amp1,    0}, {Amp2,    0}, {Layr, Layr}, {Tune, Temp}},
    {{scnp,    0}, {scnm,    0}, {Dly1,    0}, {   0,    0}, {SNGp,    0}, {SNGm,    0}, {Amp1,    0}, {Amp2,    0}, {Layr, Layr}, {Tune, Temp}},
    {{scnp,    0}, {scnm,    0}, {MDl1,    0}, {   0,    0}, {SNGp,    0}, {SNGm,    0}, {Amp1,    0}, {Amp2,    0}, {Layr, Layr}, {Tune, Temp}},
    {{scnp,    0}, {scnm,    0}, {MDl1,    0}, {L2Re,    0}, {SNGp,    0}, {SNGm,    0}, {Amp1,    0}, {Amp2,    0}, {Layr, Layr}, {Tune, Temp}},
    {{scnp,    0}, {scnm,    0}, {MDl1,    0}, {L2Pl,    0}, {SNGp,    0}, {SNGm,    0}, {Amp1,    0}, {Amp2,    0}, {Layr, Layr}, {Tune, Temp}},
    {{scnp,    0}, {scnm,    0}, {MDl1,    0}, {L2Pl,    0}, {SNGp,    0}, {SNGm,    0}, {Amp1,    0}, {Amp2,    0}, {Layr, Layr}, {Tune, Temp}},
    {{scnp,    0}, {scnm,    0}, {MDl1,    0}, {   0,    0}, {SNGp,    0}, {SNGm,    0}, {Amp1,    0}, {Amp2,    0}, {Layr, Layr}, {Tune, Temp}}
  },
  { //Demo Song für Video
    //Switch01,     Switch02,     Switch03,     Switch04,     Switch05,     Switch06,     Switch07,     Switch08,     Switch09      Switch10,
    //Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2
    {{scnp, scnp}, {scnm, scnm}, {Drv1, Drv2}, {Dly1, Dly2}, {SNGp, SNGp}, {SNGm, SNGm}, {Sc01, Sc03}, {Sc02, Sc04}, {Layr, Layr}, {Tune, Temp}},
    {{scnp, scnp}, {scnm, scnm}, {Drv1, Drv2}, {Dly1, Dly2}, {SNGp, SNGp}, {SNGm, SNGm}, {Sc01, Sc03}, {Sc02, Sc04}, {Layr, Layr}, {Tune, Temp}},
    {{scnp, scnp}, {scnm, scnm}, {Drv1, Drv2}, {Dly1, Dly2}, {SNGp, SNGp}, {SNGm, SNGm}, {Sc01, Sc03}, {Sc02, Sc04}, {Layr, Layr}, {Tune, Temp}},
    {{scnp, scnp}, {scnm, scnm}, {Drv1, Drv2}, {Dly1, Dly2}, {SNGp, SNGp}, {SNGm, SNGm}, {Sc01, Sc03}, {Sc02, Sc04}, {Layr, Layr}, {Tune, Temp}},
    {{scnp, scnp}, {scnm, scnm}, {Amp1, Drv2}, {Amp2, Dly2}, {SNGp, SNGp}, {SNGm, SNGm}, {Sc01, Sc03}, {Sc02, Sc04}, {Layr, Layr}, {Tune, Temp}},
    {{scnp, scnp}, {scnm, scnm}, {Cab1, Drv2}, {Cab2, Dly2}, {SNGp, SNGp}, {SNGm, SNGm}, {Sc01, Sc03}, {Sc02, Sc04}, {Layr, Layr}, {Tune, Temp}},
    {{scnp, scnp}, {scnm, scnm}, {Drv1, Drv2}, {Dly1, Dly2}, {SNGp, SNGp}, {SNGm, SNGm}, {Sc01, Sc03}, {Sc02, Sc04}, {Layr, Layr}, {Tune, Temp}},
    {{scnp, scnp}, {scnm, scnm}, {Drv1, Drv2}, {Dly1, Dly2}, {SNGp, SNGp}, {SNGm, SNGm}, {Sc01, Sc03}, {Sc02, Sc04}, {Layr, Layr}, {Tune, Temp}}
  },
};

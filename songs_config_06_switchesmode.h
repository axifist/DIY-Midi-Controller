const PROGMEM unsigned char songSwitchesModeProgmem[numberOfSongs][numberOfScenes][numberOfSwitches][numberOfSwitchLayers] = { //Now that every switch has assigned to something different, I use this function to tell the controller how the switch has to operate. Is it a toggle that triggers when pushed Dwn (TOGD) or when being released (TOGU)? Should it trigger when pushed Dwn (SELD) or when being released (SELU)? Should it be momentary (activated when pushed Dwn, deactivate when being released (MOMD), or activated when being released and deactivated when being pushed Dwn (MOMU)? See switches.h and switches_functions.h for details.
  { //Giggleract
    //Switch01,     Switch02,     Switch03,     Switch04,     Switch05,     Switch06,     Switch07,     Switch08,     Switch09,     Switch10
    //Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2
    {{SELD,    0}, {SELD,    0}, {TOGD,    0}, {   0,    0}, {SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD,    0}, {SELD,    0}, {TOGD,    0}, {   0,    0}, {SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD,    0}, {SELD,    0}, {TOGD,    0}, {   0,    0}, {SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD,    0}, {SELD,    0}, {TOGD,    0}, {ACTD,    0}, {SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD,    0}, {SELD,    0}, {TOGD,    0}, {   0,    0}, {SELD,    0}, {SELD,    0}, {TOGD,    0}, {TOGD,    0}, {TOGD, TOGD}, {TOGD, SELD}}
  },
  { //Demo Song für Video
    //Switch01,     Switch02,     Switch03,     Switch04,     Switch05,     Switch06,     Switch07,     Switch08,     Switch09,     Switch10
    //Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2
    {{SELD, TOGD}, {SELU, TOGU}, {TOGD, MOMD}, {TOGU, MOMU}, {SELD, SELD}, {SELD, SELU}, {ACTD, ACTD}, {ACTU, ACTU}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD, TOGD}, {SELU, TOGU}, {TOGD, MOMD}, {TOGU, MOMU}, {SELD, SELD}, {SELD, SELU}, {ACTD, ACTD}, {ACTU, ACTU}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD, TOGD}, {SELU, TOGU}, {TOGD, MOMD}, {TOGU, MOMU}, {SELD, SELD}, {SELD, SELU}, {ACTD, ACTD}, {ACTU, ACTU}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELD, TOGD}, {SELU, TOGU}, {TOGD, MOMD}, {TOGU, MOMU}, {SELD, SELD}, {SELD, SELU}, {ACTD, ACTD}, {ACTU, ACTU}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELU, TOGD}, {SELU, TOGU}, {TOGD, MOMD}, {TOGU, MOMU}, {SELD, SELD}, {SELD, SELU}, {ACTD, ACTD}, {ACTU, ACTU}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELU, TOGD}, {SELD, TOGU}, {TOGD, MOMD}, {TOGU, MOMU}, {SELD, SELD}, {SELD, SELU}, {ACTD, ACTD}, {ACTU, ACTU}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELU, TOGD}, {SELD, TOGU}, {TOGD, MOMD}, {TOGU, MOMU}, {SELD, SELD}, {SELD, SELU}, {ACTD, ACTD}, {ACTU, ACTU}, {TOGD, TOGD}, {TOGD, SELD}},
    {{SELU, TOGD}, {SELD, TOGU}, {TOGD, MOMD}, {TOGU, MOMU}, {SELD, SELD}, {SELD, SELU}, {ACTD, ACTD}, {ACTU, ACTU}, {TOGD, TOGD}, {TOGD, SELD}}
  },
};

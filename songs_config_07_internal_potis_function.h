const PROGMEM char songInternalPotisFunctionProgmem[numberOfSongs][numberOfScenes][numberOfInternalPotis][numberOfPotiFunctions] = { //When I can define the functionality of every switch for every scene separately, of course I then also want this to be available for the expression pedals and thePotentiometers built onto the controller. I can even control different (here I chose 4, can be increased / decreased as you wish) modifiers simultaneously. That way I am extremely flexible with just one expression pedal!!!
  { //Giggleract
    //Poti01        Poti02        Poti03        Poti04
    //Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2
    {{Ext1,   -1}, {  -1,   -1}, {  -1,   -1}, {  -1,   -1}},
    {{Ext2,   -1}, {  -1,   -1}, {  -1,   -1}, {  -1,   -1}},
    {{  -1,   -1}, {  -1,   -1}, {  -1,   -1}, {  -1,   -1}},
    {{  -1,   -1}, {  -1,   -1}, {  -1,   -1}, {  -1,   -1}},
    {{  -1,   -1}, {  -1,   -1}, {  -1,   -1}, {  -1,   -1}},
    {{  -1,   -1}, {  -1,   -1}, {  -1,   -1}, {  -1,   -1}},
    {{  -1,   -1}, {  -1,   -1}, {  -1,   -1}, {  -1,   -1}}
  },
  { //Demo Song für Video
    //Poti01        Poti02        Poti03        Poti04
    //Fct1  Fct2    Fct1  Fct2    Fct1  Fct2    Fct1  Fct2
    {{Ext1,   -1}, {Ext2,   -1}, {Ext8, Ext5}, {Ext6, Ext7}},
    {{Ext1,   -1}, {Ext3,   -1}, {Ext8, Ext5}, {Ext6, Ext7}},
    {{Ext1,   -1}, {  -1,   -1}, {Ext8, Ext5}, {Ext6, Ext7}},
    {{Ext1,   -1}, {  -1,   -1}, {Ext8, Ext5}, {Ext6, Ext7}},
    {{Ext1,   -1}, {  -1,   -1}, {Ext8, Ext5}, {Ext6, Ext7}},
    {{Ext1,   -1}, {  -1,   -1}, {Ext8, Ext5}, {Ext6, Ext7}},
    {{Ext1,   -1}, {  -1,   -1}, {Ext8, Ext5}, {Ext6, Ext7}},
    {{Ext1,   -1}, {  -1,   -1}, {Ext8, Ext5}, {Ext6, Ext7}},
  },
};

const PROGMEM unsigned char songInfosProgmem[numberOfSongs][numberOfSongInfos] = { //Every song gets its preset on the Axe. Which one is being defined here. And the number of scenes too. !!!Beware!!! Right now I only support calling presets of bank 1 and 2, because for some reason I cannot call presets with numbers higher than 255. I know, data type unsigned char (=unsigned char) ends at 255, but switching to word (=unsigned int) didn't work (so far)
  //Giggleract

  //Preset #Scenes
  {1,      7},







  //Song 2

  //Preset #Scenes
  {127,      8},








};

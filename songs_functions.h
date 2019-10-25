void showSong() { //This function fills the left side of the display with all required infos, depending on the chosen mode
  lcd.setCursor(0, 0);
  switch (runMode) {
    case gigMode:
      lcd.print("G");
      lcd.setCursor(2, 0);
      if (songCounter + 1 < 10) {
        lcd.print(" ");
      }
      lcd.print(songCounter + 1);
      break;
    case songMode:
      lcd.print("S");
      break;
  }
  lcd.setCursor(5, 0);
  lcd.print(songName);
  lcd.setCursor(0, 1);
  if (currentScene + 1 < 10) {
    lcd.print(" ");
  }
  lcd.print(currentScene + 1); //Show the remaining amount of scenes
  lcd.print("/");
  lcd.print(songInfos[1]); //Show the remaining amount of scenes
  lcd.setCursor(6, 1);
  lcd.print(sceneName[currentScene]);
}

void showBlocks() { //This function fills the right side of the display, showing what each of the 8 switches is assigned to.
  //first row
  for (m = 0; m < 4; m++) {//4, because I have 4 switches in one row on my controller
    lcd.setCursor(17 + m * 6, 1); //Write this stuff to the right position on the display
    lcd.print(blocks[songSwitches[currentScene][m][currentSwitchLayer]]);
  }
  //second row
  for (m = 4; m < 8; m++) {
    lcd.setCursor(17 + (m - 4) * 6, 0);
    lcd.print(blocks[songSwitches[currentScene][m][currentSwitchLayer]]);
  }
}

void setLEDs() { //This function controls the LEDs according to the state of what is assigned to its switch.
  for (currentSwitch = 0; currentSwitch < numberOfSwitches; currentSwitch++) {
    for (currentBlock = 0; currentBlock < numberOfBlocks; currentBlock++) {
      //Those two ifs set the LEDs according to the effect state for switches assigned to effects
      if ((songScenes[currentScene][currentBlock] == 127) && (songSwitches[currentScene][currentSwitch][currentSwitchLayer] == currentBlock + sceneCcOffset)) {
        ledState[currentSwitch] = HIGH;
        digitalWrite(leds[currentSwitch], HIGH);
      }
      else if ((songScenes[currentScene][currentBlock] == 0) && (songSwitches[currentScene][currentSwitch][currentSwitchLayer] == currentBlock + sceneCcOffset)) {
        ledState[currentSwitch] = LOW;
        digitalWrite(leds[currentSwitch], LOW);
      }
    }

    //Now those LEDs of switches assigned to directly select a scene should show the scene status correctly
    if ((songSwitches[currentScene][currentSwitch][currentSwitchLayer] >= Sc01 && songSwitches[currentScene][currentSwitch][currentSwitchLayer] <= Sc24) && currentScene + rangeOfCcs == songSwitches[currentScene][currentSwitch][currentSwitchLayer]) {
      ledState[currentSwitch] = HIGH;
      digitalWrite(leds[currentSwitch], HIGH);
    }
    else if ((songSwitches[currentScene][currentSwitch][currentSwitchLayer] >= Sc01 && songSwitches[currentScene][currentSwitch][currentSwitchLayer] <= Sc24) && currentScene + rangeOfCcs != songSwitches[currentScene][currentSwitch][currentSwitchLayer]) {
      ledState[currentSwitch] = LOW;
      digitalWrite(leds[currentSwitch], LOW);
    }

    //Now I want to set the LED assigned to the Tune correctly
    if ((songSwitches[currentScene][currentSwitch][currentSwitchLayer] == Tune && tunerStatus == false ) || (songSwitches[currentScene][currentSwitch][currentSwitchLayer] != Tune && songSwitches[currentScene][currentSwitch][1 - currentSwitchLayer] == Tune)) {
      ledState[currentSwitch] = LOW;
      digitalWrite(leds[currentSwitch], LOW);
    }
    else if (songSwitches[currentScene][currentSwitch][currentSwitchLayer] == Tune && tunerStatus == true ) {
      ledState[currentSwitch] = HIGH;
      digitalWrite(leds[currentSwitch], HIGH);
    }

    //Switches assigned to nothing should have an off LED
    if (songSwitches[currentScene][currentSwitch][currentSwitchLayer] == 0) {
      ledState[currentSwitch] = LOW;
      digitalWrite(leds[currentSwitch], LOW);
    }
  }
}

void setFirstScene() { //The data for the first scene always needs to be delivered completely, because a previous state isn't known.
  for (currentBlock = 0; currentBlock < numberOfBlocks; currentBlock++) {
    if (songScenes[currentScene][currentBlock] != -1) {
      MIDI.sendControlChange(currentBlock + sceneCcOffset, songScenes[currentScene][currentBlock], midiChannel); //MIDI data always comes first
    }
  }
  setLEDs();
  showSong();
  showBlocks();
}

void setScene() { //This function is used when scenes are changed. It only sends CC data for changed effects
  for (currentBlock = 0; currentBlock < numberOfBlocks; currentBlock++) {
    if ((songScenes[currentScene][currentBlock] != songScenes[previousScene][currentBlock]) && (songScenes[currentScene][currentBlock] != -1)) { //Setting a CC value of -1 in the scenes config is supposed to mean that nothing should be done with it.
      MIDI.sendControlChange(currentBlock + sceneCcOffset, songScenes[currentScene][currentBlock], midiChannel); //MIDI data always comes first
    }
  }
  setLEDs();
  showSong();
  showBlocks();
}

void setSong() { //This function loads the songs' configuration from PROGMEM and prepares the selected song (sets first scene etc.)
  //First load the configurations
  for (i = 0; i < numberOfSongInfos; i++) {
    songInfos[i] = pgm_read_byte(&songInfosProgmem[currentSong][i]);
  }
  for (i = 0; i < songInfos[1]; i++) {
    for (j = 0; j < numberOfBlocksPartOne; j++) {
      songScenes[i][j] = pgm_read_byte(&songScenesPartOneProgmem[currentSong][i][j]);
    }
    for (j = 0; j < numberOfBlocksPartTwo; j++) {
      songScenes[i][j + numberOfBlocksPartOne] = pgm_read_byte(&songScenesPartTwoProgmem[currentSong][i][j]);
    }
    for (j = 0; j < numberOfBlocksPartThree; j++) {
      songScenes[i][j + numberOfBlocksPartOne + numberOfBlocksPartTwo] = pgm_read_byte(&songScenesPartThreeProgmem[currentSong][i][j]);
    }
    for (j = 0; j < numberOfBlocksPartFour; j++) {
      songScenes[i][j + numberOfBlocksPartOne + numberOfBlocksPartTwo + numberOfBlocksPartThree] = pgm_read_byte(&songScenesPartFourProgmem[currentSong][i][j]);
    }
    for (j = 0; j < numberOfInternalPotis; j++) {
      for (k = 0; k < numberOfPotiFunctions; k++) {
        songPotisFunction[i][j][k] = pgm_read_byte(&songInternalPotisFunctionProgmem[currentSong][i][j][k]);
        songPotisDirection[i][j][k] = pgm_read_byte(&songInternalPotisDirectionProgmem[currentSong][i][j][k]);
      }
    }
    for (j = 0; j < numberOfExternalPotis; j++) {
      for (k = 0; k < numberOfPotiFunctions; k++) {
        songPotisFunction[i][j + numberOfInternalPotis][k] = pgm_read_byte(&songExternalPotisFunctionProgmem[currentSong][i][j][k]);
        songPotisDirection[i][j + numberOfInternalPotis][k] = pgm_read_byte(&songExternalPotisDirectionProgmem[currentSong][i][j][k]);
      }
    }
    for (j = 0; j < numberOfSwitches; j++) {
      for (k = 0; k < numberOfSwitchLayers; k++) {
        songSwitchesModus[i][j][k] = pgm_read_byte(&songSwitchesModeProgmem[currentSong][i][j][k]);
        songSwitches[i][j][k] = pgm_read_byte(&songSwitchesProgmem[currentSong][i][j][k]);
      }
    }
    for (j = 0; j < lengthOfSceneNames; j++) {
      sceneName[i][j] = pgm_read_byte(&sceneNameProgmem[currentSong][i][j]);
    }
  }
  for (i = 0; i < lengthOfSongNames; i++) {
    songName[i] = pgm_read_byte(&songNameProgmem[currentSong][i]);
  }

  //then reset the scene counters
  currentScene = 0;
  previousScene = 0;

  //then go back to the first layer
  currentSwitchLayer = 0;

  //and turn off the LED of the function switch accordingly TODO: not necessary, if the function switch is being configured in a fixed way
  for (currentSwitch = 0; currentSwitch < numberOfSwitches; currentSwitch++) {   //Search the
    if (songSwitches[currentScene][currentSwitch][currentSwitchLayer] == Layr) { //layer switch
      ledState[currentSwitch] = LOW;
      digitalWrite(leds[currentSwitch], LOW);
    }
  }

  //reset the value of the potentiometer / expression pedal, so it gets adjusted correctly
//  for (loopThroughPotis = 0; loopThroughPotis < numberOfPotis; loopThroughPotis++) {
//    controllerValueOld[loopThroughPotis] = -1; //Here I set this value in a way, so it's != 0-127 and I set it low, so that the controllerValue gets adjusted upwards rather than downwards. This way it's more safe, e.g. if a potentiometer controlls volume, the volume goes from silence up to the adjusted value rather than being loud and then going down, which could cause hearing damage etc.
//  }

  //then finally select the right preset
  setPreset(songInfos[0] - 1);

  delay(50); //The Ultra seems to need a little pause between setting the preset and then receiving further midi data. Setting this delay < 40 ms leads to bad behaviour. I set it to 50 ms to be safe.

  //and set the first scene
  setFirstScene();
}

void nextSong() { //This function increments the songs. Depending on the mode this means either the next song that is configured here or the next song in the current setlist.
  songCounter++;
  switch (runMode) {
    case gigMode:
      if (songCounter == gigInfos[currentGig]) {
        songCounter = 0;
      }
      currentSong = gigSongs[currentGig][songCounter] - 1;
      break;
    case songMode:
      if (songCounter == numberOfSongs) {
        songCounter = 0;
      }
      currentSong = songCounter;
      EEPROM.update(songCounterMemory, songCounter); //For me it's a good thing for the controller to remember the last selected song. But this doesn't make sense for gigs, because they always begin at the first song.
      break;
  }
  setSong(); //Ok, now we know which song is supposed to be loaded, so let's load it
}

void prevSong() { //Same as above, only for the previous song
  switch (runMode) {
    case gigMode:
      if (songCounter == 0) {
        songCounter = gigInfos[currentGig] - 1;
      }
      else {
        songCounter--;
      }
      currentSong = gigSongs[currentGig][songCounter] - 1;
      break;
    case songMode:
      if (songCounter == 0) {
        songCounter = numberOfSongs - 1;
      }
      else {
        songCounter--;
      }
      currentSong = songCounter;
      EEPROM.update(songCounterMemory, songCounter);
      break;
  }
  setSong();
}

void nextScene() { //This function increments the scenes. When you reach the last scene, it switches back to the first scene. TODO: Maybe for songs this isn't the best idea?
  previousScene = currentScene;
  if (currentScene == songInfos[1] - 1) {
    currentScene = 0;
  }
  else {
    currentScene++;
  }
  setScene();
}

void prevScene() { //Same as above, only decrements the scenes.
  previousScene = currentScene;
  if (currentScene == 0) {
    currentScene = songInfos[1] - 1;
  }
  else {
    currentScene--;
  }
  setScene();
}

void callScene(unsigned char scene) { //This function allows to select scenes directly. E.g. if you want to call scene 5, do this with callScene(5).
  previousScene = currentScene;
  currentScene = scene - 1;
  setScene();
}

void initSong() { //This song sets the song right after the controller booted. Which song depends on the mode, the current setlist or the song stored into EEPROM.
  switch (runMode) {
    case gigMode:
      songCounter = 0;
      currentSong = gigSongs[currentGig][songCounter] - 1;
      break;
    case songMode:
      songCounter = EEPROM.read(songCounterMemory);
      currentSong = songCounter;
      break;
  }
  setSong();
}

void changeSwitchLayer() { //This function toggles the switches' functionality layer and sets the LEDs and the right side of the display accordingly. In case one wants to have more than 2 switch layers, it circles through them. But then the LED status doesn't work anymore. An LED with different colors etc would be required then.
  if (currentSwitchLayer == numberOfSwitchLayers - 1) {
    currentSwitchLayer = 0;
  }
  else {
    currentSwitchLayer = !currentSwitchLayer;
  }
  setLEDs();
  showBlocks();
}

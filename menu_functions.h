unsigned char LCDbuttons() { //The 16x2 display I use for my prototype also has a "keyboard shield". Those buttons are all connected to A0 and are distinguished by the different resistance for every button. For each button the Arduino measures a different voltage. Those are being interpreted here. I built the menu buttons on the actual controller the same way, so I can test and configure my code with the prototype, in case the real one isn't at hand.
  menuButtonsReading = analogRead(menuButtonsPin); //I measured the values for every button. The values used below lie in the middle of those values. Do your own measurements to be safe!
  if (menuButtonsReading > 872) {
    return menuButtonNone;
  }
  if (menuButtonsReading <  65) {
    return menuButtonValueRight;
  }
  if (menuButtonsReading < 218) {
    return menuButtonValueLeft;
  }
  if (menuButtonsReading < 392) {
    return menuButtonCategoryRight;
  }
  if (menuButtonsReading < 600) {
    return menuButtonCategoryLeft;
  }
  if (menuButtonsReading < 872) {
    return menuButton;
  }
  if (menuButtonsReading == 0) {
    return menuButtonNone;
  }
  return 0;
};

void menu() {
  lcd.clear();
  lcd.begin(displayWidth, displayHeight);
  lcd.setCursor(0, 0);
  lcd.print("M");
  while (!exitStatusMenu) {
    lcd.setCursor(2, 0);
    lcd.print(menuItemsString[menuItem1]);
    lcd.setCursor(2, 1);
    switch (menuItem1) {
      case 0: //mode
        menuItem2 = runMode;
        sizeOfSubmenu = numberOfmodeItems;
        sizeOfSubmenuItems = sizeOfmodeItems;
        lcd.print(modeItemsString[menuItem2]);
        break;
      case 1: //gig
        menuItem2 = currentGig;
        sizeOfSubmenu = numberOfGigs;
        sizeOfSubmenuItems = sizeOfGigNames;
        lcd.print(nameOfGig[menuItem2]);
        break;
      case 2: //LED dimmer
        menuItem2 = ledDimmerValue;
        sizeOfSubmenu = numberOfledDimmerValueItems;
        sizeOfSubmenuItems = sizeOfledDimmerValueItems;
        lcd.print(ledDimmerValueItemsString[menuItem2]);
        break;
      case 3: //tuner notes
        menuItem2 = tunerNoteSetting;
        sizeOfSubmenu = numberOftunerNotesItems;
        sizeOfSubmenuItems = sizeOftunerNotesItems;
        lcd.print(tunerNotesItemsString[menuItem2]);
        break;
      case 4: //MIDI channel
        menuItem2 = midiChannelEeprom;
        sizeOfSubmenu = numberOfmidiChannelItems;
        sizeOfSubmenuItems = sizeOfmidiChannelItems;
        lcd.print(midiChannelItemsString[menuItem2]);
        break;
      case 5: //debounce time
        menuItem2 = debounceTimeOfSwitches;
        sizeOfSubmenu = numberOfdebounceTimeOfSwitchesItems;
        sizeOfSubmenuItems = sizeOfdebounceTimeOfSwitchesItems;
        lcd.print(debounceTimeOfSwitchesItemsString[menuItem2]);
        break;
      default:
        break;
    }
    for (printSpaces = 0; printSpaces < 38 - sizeOfSubmenuItems; printSpaces++) {
      lcd.print(" ");
    }
    menuButtonsReading = LCDbuttons();
    switch (menuButtonsReading) {
      case menuButton:
        exitStatusMenu = true;
        delay(menuDelay);
        break;
      case menuButtonCategoryLeft:
        if (menuItem1 < 1) {
          menuItem1 = (numberOfmenuItems) - 1;
        }
        else {
          menuItem1--;
        }
        delay(menuDelay);
        break;
      case menuButtonCategoryRight:
        if (menuItem1 < (numberOfmenuItems) - 1) {
          menuItem1++;
        }
        else {
          menuItem1 = 0;
        }
        delay(menuDelay);
        break;
      case menuButtonValueLeft:
        if (menuItem2 < 1) {
          menuItem2 = sizeOfSubmenu - 1;
        }
        else {
          menuItem2--;
        }
        switch (menuItem1) {
          case 0: //mode
            runMode = menuItem2;
            break;
          case 1: //gig
            currentGig = menuItem2;
            break;
          case 2: //LED dimmer
            ledDimmerValue = menuItem2;
            break;
          case 3: //tuner notes
            tunerNoteSetting = menuItem2;
            break;
          case 4: //MIDI channel
            midiChannelEeprom = menuItem2;
            break;
          case 5: //debounce time
            debounceTimeOfSwitches = menuItem2;
            break;
          default:
            break;
        }
        delay(menuDelay);
        break;
      case menuButtonValueRight:
        if (menuItem2 < sizeOfSubmenu - 1) {
          menuItem2++;
        }
        else {
          menuItem2 = 0;
        }
        switch (menuItem1) {
          case 0: //mode
            runMode = menuItem2;
            break;
          case 1: //gig
            currentGig = menuItem2;
            break;
          case 2: //LED dimmer
            ledDimmerValue = menuItem2;
            break;
          case 3: //tuner notes
            tunerNoteSetting = menuItem2;
            break;
          case 4: //Midi channel
            midiChannelEeprom = menuItem2;
            break;
          case 5: //debounce time
            debounceTimeOfSwitches = menuItem2;
            break;
          default:
            break;
        }
        delay(menuDelay);
        break;
      case menuButtonNone:
        break;
      default:
        break;
    }
  }
  if (ledDimmerValue == 1 && ledDimmerValue != EEPROM.read(ledDimmerValueMemory)) {
    for (currentSwitch = 0; currentSwitch < numberOfSwitches; currentSwitch++) {
      pinMode(leds[currentSwitch], OUTPUT);
    }
    pinMode(LEDBPM, OUTPUT);
  }
  else if (ledDimmerValue == 0 && ledDimmerValue != EEPROM.read(ledDimmerValueMemory)) {
    for (currentSwitch = 0; currentSwitch < numberOfSwitches; currentSwitch++) {
      pinMode(leds[currentSwitch], INPUT);
    }
    pinMode(LEDBPM, INPUT);
  }
  exitStatusMenu = false;
  midiChannel = midiChannelItems[midiChannelEeprom];
  menuItem1 = 0; //Next time let the menu start at the first item again
  initSong();
  write_eeprom(); //As soon as I exit the menu, the changes are safed to EEPROM. This function can be found in eeprom_functions.h
  mainScreen(); //After that the main screen is shown again.
}

void buttonsGO() {
  switch (LCDbuttons()) {
    case menuButton:  //As soon as the "select" button (left one of the menu buttons) is being pushed, the Arduino changes to
      delay(menuDelay); //
      menu();           //the menu. This function can be found in menu_functions.h
      break;
    case menuButtonCategoryLeft:
      prevSong();
      delay(menuDelay);
      break;
    case menuButtonCategoryRight:
      nextSong();
      delay(menuDelay);
      break;
    case menuButtonValueLeft:
      prevScene();
      delay(menuDelay);
      break;
    case menuButtonValueRight:   //In case the other buttons are being pressed without being in the menu, one can give them other useful functions.
      nextScene();      //This is just an example, probably not the most useful one.
      delay(menuDelay);
      break;
  }
}

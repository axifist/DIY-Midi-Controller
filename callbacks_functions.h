void handleSysEx(unsigned char *array, unsigned sysExSize) { //This function is being called as soon as SysEx data is being received from the Axe. They get analysed here. For me the two relevant things are tuner and tempo. It's important to check the data thoroughly. Back when I didn't do this, the Controller hung up many times when it started (being connected) or when I connected it to the Ultra while running. Must have been because of incomplete SysEx data, which lead to misinterpretation?
  lcd.createChar(0, tuner0);
  lcd.createChar(1, tuner1);
  lcd.createChar(2, tuner2);
  lcd.createChar(3, tuner3);
  lcd.createChar(4, tuner4);
  lcd.createChar(5, tuner5);
  lcd.createChar(6, tuner6);
  lcd.createChar(7, tuner7);

  if ((sysExSize == 10) && (array[0] == 0xF0) && (array[5] == 0x0D)) { //Tuner SysEx
    tunerStatus = true;
    lcd.setCursor(0, 0);
    lcd.print("T");

    lcd.setCursor(7, 0);
    switch (tunerNoteSetting) { //Which ever system you chose in the menu, it's being called here.
      case 0:
        lcd.print(notesEnglishFlat[array[6]]);
        break;
      case 1:
        lcd.print(notesEnglishSharp[array[6]]);
        break;
      case 2:
        lcd.print(notesGermanFlat[array[6]]);
        break;
      case 3:
        lcd.print(notesGermanSharp[array[6]]);
        break;
      case 4:
        lcd.print(notesFrenchFlat[array[6]]);
        break;
      case 5:
        lcd.print(notesFrenchSharp[array[6]]);
        break;
      default:
        break;
    }

    tunerFine = array[8];
    if (tunerFine <= 62) {      //When the tuning is too low
      lcd.setCursor(1, 0);      //
      lcd.print("     >");      //an arrow, aiming to the right, is shown left to the note
      lcd.setCursor(10, 0);     //
      lcd.print("      ");      //
    }
    else if (tunerFine >= 64) { //When the tuning is too high
      lcd.setCursor(1, 0);      //
      lcd.print("      ");      //
      lcd.setCursor(10, 0);     //
      lcd.print("<     ");      //an arrow, aiming to the left, is shown right of the note
    }
    else if (tunerFine == 63) { //when the tuning is correct
      lcd.setCursor(1, 0);      //
      lcd.print("     >");      //both
      lcd.setCursor(10, 0);     //
      lcd.print("<     ");      //arrows appear. Note, that I'm more strict than the Axe itself. It shows both arrows not only if the tunerFine value is 63, but for 62, 63 or 64. An option would be to show both arrows for 62 and 64 and two arrows on each side for 63.
    }
    else {
      lcd.setCursor(1, 0);      //In case any other values are received
      lcd.print("      ");      //absolutely nothing
      lcd.setCursor(9, 0);      //
      lcd.print("       ");     //is supposed to be displayed.
    }
    tunerDisplay();           //This function shows the tuning in more detail, just like on the Axe. This function is defined in tuner_functions.h
    tunerLastTime = millis(); //This variable is required for the tuner to disappear, as soon as the Axe doesn't send any more tuner data. This way the tuner screen disappears no matter if the tuner is being deactivated via the footswitch or on the Axe. The turning off is being realized in the tunerOff() function you see below.
    for (currentSwitch = 0; currentSwitch < numberOfSwitches; currentSwitch++) { //The tuner LED should be controlled by the interaction with the Ultra. That way the tuner cannot be "activated" when no Ultra is connected, which makes sense. Possibly I'll do the same for activating effects, but this is much more complicated...
      if (songSwitches[currentScene][currentSwitch][currentSwitchLayer] == Tune) {
        digitalWrite(leds[currentSwitch], HIGH);
        ledState[currentSwitch] = HIGH;
      }
    }
  }

  if ((sysExSize == 7) && (array[0] == 0xF0) && (array[5] == 0x10)) { //If tempo SysEx data is being received, the tempo LED
    digitalWrite(LEDBPM, HIGH);                                       //is turned on
    tempoLedStatus = HIGH;                                            //and the status is set accordingly
    tempoLedLastTime = millis();                                      //In void(loop) I call tapledOff() for the tempo LED to turn off again. This needs to be done outside of handleSysEx(), because that function is only being called, when SysEx data is being received.
  }
}

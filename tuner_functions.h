void tunerDisplay() {  //This function draws the fine tuning
  lcd.setCursor(0, 1); //in the display's second row. There are many possible designs. I chose this one, because it fits the display perfectly for a smooth movement.

  //1.: The value is lower than what the Axe actually sends. In this case just show the tuning to be too low.
  if (tunerFine <= 15) {
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print("        ");
  }

  //2.: Tuning is too low
  else if ((tunerFine >= 16) && (tunerFine <= 61)) {
    tunerDividend = tunerFine - 16;
    tunerRemainder = tunerDividend % 6;
    tunerQuotient = tunerDividend / 6;
    for (l = 0; l < tunerQuotient; l++) {
      lcd.print(" ");
    }
    if ((tunerRemainder == 4) || (tunerRemainder == 5)) {
      lcd.print(" ");
    }
    else {
      lcd.write(byte(tunerRemainder));
    }
    for (l = 0; l < 7 - tunerQuotient; l++) {
      lcd.print(rectangle);
    }
    lcd.print("        ");
  }

  //3.: Tuning is correct
  else if ((tunerFine >= 62) && (tunerFine <= 64)) {
    lcd.print("                ");
  }

  //4.: Tuning is too high
  else if ((tunerFine >= 65) && (tunerFine <= 110)) {
    lcd.print("        ");
    tunerDividend = tunerFine - 65;
    tunerRemainder = tunerDividend % 6;
    tunerQuotient = tunerDividend / 6;
    for (l = 0; l < tunerQuotient; l++) {
      lcd.print(rectangle);
    }
    if ((tunerRemainder == 4) || (tunerRemainder == 5)) {
      lcd.print(rectangle);
    }
    else {
      lcd.write(byte(tunerRemainder + 4));
    }
    for (l = 0; l < 7 - tunerQuotient; l++) {
      lcd.print(" ");
    }
  }

  //5.: The value is higher than what the Axe actually sends. In this case just show the tuning to be too high.
  else if (tunerFine >= 111) {
    lcd.print("        ");
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
    lcd.print(rectangle);
  }
};

void tunerOff() {
  if (millis() - tunerLastTime >= 100 && tunerStatus == true) { //Required so the tuner screen disappears, as soon as no more SysEx tuner data is being received. I chose 100ms, because at 20ms it started to go crazy, because the time between tuner data seems to be around 20ms. 50ms would have been safe, but to be absolutely safe I chose 100ms. Even more would be ok, but one has to compromise ;-)
    tunerStatus = false;

    for (currentSwitch = 0; currentSwitch < numberOfSwitches; currentSwitch++) {
      if (songSwitches[currentScene][currentSwitch][currentSwitchLayer] == Tune) {
        digitalWrite(leds[currentSwitch], LOW);
        ledState[currentSwitch] = LOW;
      }
    }
    mainScreen(); //So, if the last tuner data was more than 100ms ago, I switch back to the mainScreen(), which is defined in display_functions.h
  }
}

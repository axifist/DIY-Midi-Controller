void initial() { //This function initializes all connected stuff like switches, LEDs etc. Also the arrays are being filled according to their size. I'm not 100% sure if this is required, but I think it's a good idea to be sure all memory contains senseful values
  lcd.createChar(0, sinus1);
  lcd.createChar(1, sinus2);
  lcd.createChar(2, sinus3);
  lcd.createChar(3, sinus4);
  lcd.createChar(4, sinus5);
  lcd.createChar(5, sinus6);
  lcd.createChar(6, sinus7);
  lcd.createChar(7, sinus8);
  lcd.setCursor(0, 0);
  for (loopThroughSwitches = 0; loopThroughSwitches < numberOfSwitches; loopThroughSwitches++) {
    //Set LED brightness according to the settings (it's a hack, I know, but for now this has to do the job)
    if (ledDimmerValue == 1) {
      pinMode(leds[loopThroughSwitches], OUTPUT);
    }
    else if (ledDimmerValue == 0) {
      pinMode(leds[loopThroughSwitches], INPUT); //Bit strange: If I set this to INPUT_PULLUP rather than INPUT, I'd expect the LEDs to be VERY dark. But they aren't...
    }
    
    pinMode(switches[loopThroughSwitches], INPUT); //It would have been possible to use the resistors already integrated into the Arduino. In that case use INPUT_PULLUP instead of INPUT. I chose to use external resistors.
    //Arrays for switches
    switchState[loopThroughSwitches] = LOW;
    switchStateOld[loopThroughSwitches] = LOW;
    switchReading[loopThroughSwitches] = LOW;
    switchLastDebounceTime[loopThroughSwitches] = 0;

    //The for loop iterates through all switches, but since every switch has its LED I can initialize them here too.
    ledState[loopThroughSwitches] = LOW;
    ledLastTime[loopThroughSwitches] = 0;
    digitalWrite(leds[loopThroughSwitches], HIGH);

    //And meanwhile the display shows nice stuff
    lcd.setCursor(0 + 4 * loopThroughSwitches, 0);
    lcd.write(byte(0));
    delay(introSpeed);
    lcd.setCursor(0 + 4 * loopThroughSwitches, 0);
    lcd.write(byte(1));
    delay(introSpeed);
    lcd.setCursor(1 + 4 * loopThroughSwitches, 0);
    lcd.write(byte(2));
    delay(introSpeed);
    lcd.setCursor(1 + 4 * loopThroughSwitches, 0);
    lcd.write(byte(3));
    delay(introSpeed);
    lcd.setCursor(2 + 4 * loopThroughSwitches, 1);
    lcd.write(byte(4));
    delay(introSpeed);
    lcd.setCursor(2 + 4 * loopThroughSwitches, 1);
    lcd.write(byte(5));
    delay(introSpeed);
    lcd.setCursor(3 + 4 * loopThroughSwitches, 1);
    lcd.write(byte(6));
    delay(introSpeed);
    lcd.setCursor(3 + 4 * loopThroughSwitches, 1);
    lcd.write(byte(7));
    delay(introSpeed);

    digitalWrite(leds[loopThroughSwitches], LOW);
  }

  //The finale grande is being accompanied by the tempo LED being the top center of the controller. Almost a divine theme!
  if (ledDimmerValue == 1) { //Only the tempo LED doesn't have a button assigned to it, so it needs to be initialized separately.
    pinMode(LEDBPM, OUTPUT);
  }
  else if (ledDimmerValue == 0) {
    pinMode(LEDBPM, INPUT);
  }
  digitalWrite(LEDBPM, HIGH);
  lcd.setCursor((displayWidth - lengthOfControllerTitle) / 2, 0);
  lcd.print(controllerTitle);
  delay(666); //Oh the devil
  lcd.setCursor((displayWidth - lengthOfControllerSubtitle) / 2, 1);
  lcd.print(controllerSubtitle);
  digitalWrite(LEDBPM, LOW);

  //Going back down to earth (or hell because of the 666ms delay before?) and starting to do what's among the most precious things: Playing music :-)
  digitalWrite(LED09, HIGH);
  digitalWrite(LED10, HIGH);
  delay(introSpeed * 4);
  digitalWrite(LED09, LOW);
  digitalWrite(LED10, LOW);
  digitalWrite(LED05, HIGH);
  digitalWrite(LED08, HIGH);
  delay(introSpeed * 4);
  digitalWrite(LED05, LOW);
  digitalWrite(LED08, LOW);
  digitalWrite(LED01, HIGH);
  digitalWrite(LED04, HIGH);
  delay(introSpeed * 4);
  digitalWrite(LED01, LOW);
  digitalWrite(LED04, LOW);
  digitalWrite(LED02, HIGH);
  digitalWrite(LED03, HIGH);
  delay(introSpeed * 4);
  digitalWrite(LED02, LOW);
  digitalWrite(LED03, LOW);
  digitalWrite(LED06, HIGH);
  digitalWrite(LED07, HIGH);
  delay(introSpeed * 4);
  digitalWrite(LED06, LOW);
  digitalWrite(LED07, LOW);

  //Not to forget about the potentiometers (those on the controller and in the expression pedals, they need to get initialized too.
  for (loopThroughPotis = 0; loopThroughPotis < numberOfPotis; loopThroughPotis++) {
    potiValue[loopThroughPotis] = 0;
    potiValueOld[loopThroughPotis] = 0;
    controllerValue[loopThroughPotis] = 0;
    controllerValueOld[loopThroughPotis] = 0;
  }

  initSong(); //At the end of the initialization I want to load the song which should be shown first. The actual song depends on the mode.
}

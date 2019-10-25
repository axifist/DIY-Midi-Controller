void switchAction(bool s) { //This function differentiates between the "real" CC values and the "fake" CC values. The "fake" CC values can be interpreted as the added functionality to the Ultra, e.g. scenes etc.
  switch (songSwitches[currentScene][loopThroughSwitches][currentSwitchLayer]) {
    //case 0: //Switch deactivated, so there's nothing happening here
    //  break;
    case scnp:
      nextScene();
      break;
    case scnm:
      prevScene();
      break;
    case SNGp:
      nextSong();
      break;
    case SNGm:
      prevSong();
      break;
    case Layr:
      changeSwitchLayer();
      break;
    case Sc01:
      callScene(1);
      break;
    case Sc02:
      callScene(2);
      break;
    case Sc03:
      callScene(3);
      break;
    case Sc04:
      callScene(4);
      break;
    case Sc05:
      callScene(5);
      break;
    case Sc06:
      callScene(6);
      break;
    case Sc07:
      callScene(7);
      break;
    case Sc08:
      callScene(8);
      break;
    case Sc09:
      callScene(9);
      break;
    case Sc10:
      callScene(10);
      break;
    case Sc11:
      callScene(11);
      break;
    case Sc12:
      callScene(12);
      break;
    case Sc13:
      callScene(13);
      break;
    case Sc14:
      callScene(14);
      break;
    case Sc15:
      callScene(15);
      break;
    case Sc16:
      callScene(16);
      break;
    case Sc17:
      callScene(17);
      break;
    case Sc18:
      callScene(18);
      break;
    case Sc19:
      callScene(19);
      break;
    case Sc20:
      callScene(20);
      break;
    case Sc21:
      callScene(21);
      break;
    case Sc22:
      callScene(22);
      break;
    case Sc23:
      callScene(23);
      break;
    case Sc24:
      callScene(24);
      break;
    default:
      MIDI.sendControlChange(songSwitches[currentScene][loopThroughSwitches][currentSwitchLayer], 127 * s, midiChannel);
      songScenes[currentScene][songSwitches[currentScene][loopThroughSwitches][currentSwitchLayer] - sceneCcOffset] = 127 * s; //This line overwrites the configured state of the effect. That way, when I switch back to this scene, the changes persist. TODO: Make this configurable?!
      break;
  }
  if (songSwitches[currentScene][loopThroughSwitches][currentSwitchLayer] != Tune) { //The tuner LED is being controlled in callbacks_functions.h.
    ledState[loopThroughSwitches] = s;
    digitalWrite(leds[loopThroughSwitches], s);
  }
}

void switchesGO() { //This function checks, if a switch has been pressed. If so, it looks up how this switch is supposed to work, what it's supposed to do and then does it accordingly.
  for (loopThroughSwitches = 0; loopThroughSwitches < numberOfSwitches; loopThroughSwitches++) {
    switchReading[loopThroughSwitches] = digitalRead(switches[loopThroughSwitches]);
    if (switchReading[loopThroughSwitches] != switchStateOld[loopThroughSwitches]) {
      switchLastDebounceTime[loopThroughSwitches] = millis();
    }
    if ((millis() - switchLastDebounceTime[loopThroughSwitches]) > debounceTimeOfSwitches && switchReading[loopThroughSwitches] != switchState[loopThroughSwitches]) {
      switchState[loopThroughSwitches] = switchReading[loopThroughSwitches];
      switch (songSwitchesModus[currentScene][loopThroughSwitches][currentSwitchLayer]) {
        case 0:
          //switchAction(LOW);
          break;
        case TOGD:
          if ((switchState[loopThroughSwitches] == HIGH) && (ledState[loopThroughSwitches] == LOW)) {
            switchAction(HIGH);
          }
          else if ((switchState[loopThroughSwitches] == HIGH) && (ledState[loopThroughSwitches] == HIGH)) {
            switchAction(LOW);
          }
          break;
        case TOGU:
          if ((switchState[loopThroughSwitches] == LOW) && (ledState[loopThroughSwitches] == LOW)) {
            switchAction(HIGH);
          }
          else if ((switchState[loopThroughSwitches] == LOW) && (ledState[loopThroughSwitches] == HIGH)) {
            switchAction(LOW);
          }
          break;
        case MOMD:
          if (switchState[loopThroughSwitches] == HIGH) {
            switchAction(HIGH);
          }
          else if (switchState[loopThroughSwitches] == LOW) {
            switchAction(LOW);
          }
          break;
        case MOMU:
          if (switchState[loopThroughSwitches] == LOW) {
            switchAction(HIGH);
          }
          else if (switchState[loopThroughSwitches] == HIGH) {
            switchAction(LOW);
          }
          break;
        case SELD: //e.g. tap tempo, next/prev scene/song
          if (switchState[loopThroughSwitches] == HIGH) {
            switchAction(HIGH);
            ledLastTime[loopThroughSwitches] = millis(); //Required for the ledOff() function, that turns the LED back off.
          }
          else if (switchState[loopThroughSwitches] == LOW) {
            ledState[loopThroughSwitches] = LOW;
            digitalWrite(leds[loopThroughSwitches], LOW);
          }
          break;
        case SELU: //e.g. tap tempo, next/prev scene/song
          if (switchState[loopThroughSwitches] == HIGH) {
            ledState[loopThroughSwitches] = LOW;
            digitalWrite(leds[loopThroughSwitches], LOW);
          }
          else if (switchState[loopThroughSwitches] == LOW) {
            switchAction(HIGH);
            ledLastTime[loopThroughSwitches] = millis(); //Required for the ledOff() function, that turns the LED back off.
          }
          break;
        case ACTD: //e.g. select scene
          if (switchState[loopThroughSwitches] == HIGH) {
            switchAction(HIGH);
          }
          break;
        case ACTU: //e.g. select scene
          if ((switchState[loopThroughSwitches] == LOW) && (ledState[loopThroughSwitches] == LOW)) {
            switchAction(HIGH);
          }
          break;
        default:
          break;
      }
    }
    switchStateOld[loopThroughSwitches] = switchReading[loopThroughSwitches];
  }
}

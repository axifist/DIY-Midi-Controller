void ledOff() { //If a switch is assigned to SELU or SELD, I need this function to handle the LED status. For details, see switches.h
  for (currentSwitch = 0; currentSwitch < numberOfSwitches; currentSwitch++) {
    if (((songSwitchesModus[currentScene][currentSwitch][currentSwitchLayer] == SELU) || (songSwitchesModus[currentScene][currentSwitch][currentSwitchLayer] == SELD)) && ((millis() - ledLastTime[currentSwitch]) >= ledLastTimeTimeout)) {
      ledState[currentSwitch] = LOW;
      digitalWrite(leds[currentSwitch], LOW);
    }
  }
}

void tempoLedOff() {
  if (millis() - tempoLedLastTime >= tunerLedTimeout && tempoLedStatus == HIGH) { //On the Ultra (most probably on all versions of the Axe) the tempo LED is on for 100ms (defined in tuner.h). That's why I chose this value, see tuner.h
    digitalWrite(LEDBPM, LOW);
    tempoLedStatus = LOW;
  }
}

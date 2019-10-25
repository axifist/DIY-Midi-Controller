void write_eeprom() { //This function saves all variable values, which need to be restored upon (re)start, in EEPROM. To keep the EEPROM from wearing out too soon I chose to use EEPROM.update instead of EEPROM.write, because EEPROM.update only writes in case the value has changed.
  EEPROM.update(runModeMemory, runMode);
  EEPROM.update(currentGigMemory, currentGig);
  EEPROM.update(ledDimmerValueMemory, ledDimmerValue);
  EEPROM.update(tunerNoteSettingMemory, tunerNoteSetting);
  EEPROM.update(midiChannelEepromMemory, midiChannelEeprom);
  EEPROM.update(debounceTimeOfSwitchesMemory, debounceTimeOfSwitches);
}

void read_eeprom() { //This function reads the data from EEPROM, which is done at startup of the Arduino.
  runMode = EEPROM.read(runModeMemory);
  currentGig = EEPROM.read(currentGigMemory);
  ledDimmerValue = EEPROM.read(ledDimmerValueMemory);
  tunerNoteSetting = EEPROM.read(tunerNoteSettingMemory);
  midiChannelEeprom = EEPROM.read(midiChannelEepromMemory);
  debounceTimeOfSwitches = EEPROM.read(debounceTimeOfSwitchesMemory);

  midiChannel = midiChannelItems[midiChannelEeprom]; //Required, because the first position in an array is always 0, whereas the first midiChannel is 1.
}

//When this code is being loaded onto a new Arduino, it crashes, because it wants to load data from the EEPROM that isn't there. This function tries to check out if the Arduino has been used before. If not, the EEPROM is being filled with default values.
//TODO: Still needs to be tested with a completely new Arduino.
void first_run() {
  if (EEPROM.read(memoryLocationOfIndication) != 1) { //On the last byte I store a 1 which indicates that this Arduino has been used with this code before.
    lcd.setCursor(1, 0);
    lcd.print("This is the first run on this Arduino");
    lcd.setCursor(14, 1);
    lcd.print("INITIALIZING");
    lcd.setCursor(39, 1);
    lcd.print("%");
    for (loopThroughEeprom = 0; loopThroughEeprom < EEPROM.length(); loopThroughEeprom++) {
      EEPROM.write(loopThroughEeprom, 0);
      percentageOfInitialisation = ((float)loopThroughEeprom / (EEPROM.length() - 1)) * 100;
      lcd.setCursor(36, 1);
      if (percentageOfInitialisation < 10) {
        lcd.print("  ");
      }
      else if (percentageOfInitialisation < 100) {
        lcd.print(" ");
      }
      lcd.print(percentageOfInitialisation);
    }
    EEPROM.write(runModeMemory, runMode);
    EEPROM.write(currentGigMemory, currentGig);
    EEPROM.write(tunerNoteSettingMemory, tunerNoteSetting);
    EEPROM.write(midiChannelEepromMemory, midiChannelEeprom);
    EEPROM.write(ledDimmerValueMemory, ledDimmerValue);
    EEPROM.write(songCounterMemory, songCounter);
    EEPROM.write(debounceTimeOfSwitches, debounceTimeOfSwitchesMemory);
    EEPROM.write(memoryLocationOfIndication, valueOfIndication);
    delay(1000);
    lcd.clear();
  }
}

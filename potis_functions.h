void potisGO() { //This function is being called by void loop(). As soon as a potentiometer is being used (turned), and only then, CC data is being sent. Which data exactly is being configured in song_config_7_potis.h
  for (loopThroughPotis = 0; loopThroughPotis < numberOfPotis; loopThroughPotis++) {
    potiValue[loopThroughPotis] = analogRead(poti[loopThroughPotis]) * 0.4 + potiValueOld[loopThroughPotis] * 0.6; //This line smooths the measured values. The measured values of an unused potentiometer can jumb back and forth between values. Without the smoothing the controller would constantly send CC data, which I don't want. There are other ways to smooth, but this one works best for me. The values 0.4 and 0.6 need to add up to 1.0. 0.4 and 0.6 gave the best results. Change to taste!
    controllerValue[loopThroughPotis] = map(potiValue[loopThroughPotis], potiValueCalibrationMinimumLevel[loopThroughPotis], potiValueCalibrationMaximumLevel[loopThroughPotis], controllerValueMinimumLevel[loopThroughPotis], controllerValueMaximumLevel[loopThroughPotis]); //Here the measured values are scaled down to the needed values. In most cases this will be 0 to 127, because that's what the MIDI protocol defines.
    for (potiFunction = 0; potiFunction < numberOfPotiFunctions; potiFunction++) { //All functions one potentiometer / expression pedal can have are being considered
      if (controllerValue[loopThroughPotis] != controllerValueOld[loopThroughPotis] && songPotisFunction[currentScene][loopThroughPotis][potiFunction] != -1) { //Only send CC data in case the potentiometer / expression pedal is being used (turned) and in case it's not deactivated
        switch (songPotisDirection[currentScene][loopThroughPotis][potiFunction]) {
          case 1: //normal behavior
            MIDI.sendControlChange(songPotisFunction[currentScene][loopThroughPotis][potiFunction], controllerValue[loopThroughPotis], midiChannel);
            break;
          case 0: //inverted behavior
            MIDI.sendControlChange(songPotisFunction[currentScene][loopThroughPotis][potiFunction], controllerValueMaximumLevel[loopThroughPotis] - controllerValue[loopThroughPotis], midiChannel);
            break;
        }
      }
    }
    controllerValueOld[loopThroughPotis] = controllerValue[loopThroughPotis];
    potiValueOld[loopThroughPotis] = potiValue[loopThroughPotis];
  }
}

//In case I'll implement sending SysEx data with the potentiometers, here's what's needed.
//unsigned char Compressor1Threshold[12] = {0x00, 0x01, 0x74, AXEVERSION, 0x02, 0x04, 0x06, 0x00, 0x00, PARAMETERVALUES1[controllerValue[loopThroughPotis]], PARAMETERVALUES2[controllerValue[loopThroughPotis]], 0x01};
//MIDI.sendSysEx(12, Compressor1Threshold);

//Here's the function that changes presets according to the definition in the stored songs. That makes sense for my use case, where I have one preset for each song. I never need e.g. to increment or something. Below I have functions that do this, but since I don't use them, they're commented.
void setPreset(midi::DataByte currentPreset) {
  if (currentPreset < 128) {
    MIDI.sendControlChange(0, 0, midiChannel);
    MIDI.sendProgramChange(currentPreset, midiChannel);
  }
  else {
    MIDI.sendControlChange(0, 1, midiChannel);
    MIDI.sendProgramChange(currentPreset - 128, midiChannel);
  }
  //else if (currentPreset < 384) { //Those don't work right now, because I cannot seem to get integers in PROGMEM to be loaded correctly
  //  MIDI.sendControlChange(0, 2, midiChannel);
  //  MIDI.sendProgramChange(currentPreset - 256, midiChannel);
  //}
}

//If I want to increment / decrement one preset, I execute presetUp(1) / presetDown(1). If I want to increment a whole bank, I do presetUp(128) / presetDown(128). Any steps are possible, except jumping directly to the first preset of a bank. I probably won't implement it, because I don't need it. If you do, it shouldn't be too hard ;-)

//Don't need this right now, so it's commented
//void presetUp(midi::DataByte presetChangeAmount) {
//  currentPreset = currentPreset + presetChangeAmount;
//  if (currentPreset < 128) {
//    MIDI.sendControlChange(0, 0, midiChannel);
//    MIDI.sendProgramChange(currentPreset, midiChannel);
//  }
//  else if (currentPreset < 256) {
//    MIDI.sendControlChange(0, 1, midiChannel);
//    MIDI.sendProgramChange(currentPreset - 128, midiChannel);
//  }
//  else if (currentPreset < 384) {
//    MIDI.sendControlChange(0, 2, midiChannel);
//    MIDI.sendProgramChange(currentPreset - 256, midiChannel);
//  }
//  else if (currentPreset >=  384) {
//    currentPreset = 0;
//    MIDI.sendControlChange(0, 0, midiChannel);
//    MIDI.sendProgramChange(currentPreset, midiChannel);
//  }
//}

//Don't need this right now, so it's commented
//void presetDown(midi::DataByte presetChangeAmount) {
//  currentPreset = currentPreset - presetChangeAmount;
//  if (currentPreset < 0) {
//    currentPreset = 384 - presetChangeAmount;
//    MIDI.sendControlChange(0, 2, midiChannel);
//    MIDI.sendProgramChange(currentPreset - 256, midiChannel);
//  }
//  else if (currentPreset < 128) {
//    MIDI.sendControlChange(0, 0, midiChannel);
//    MIDI.sendProgramChange(currentPreset, midiChannel);
//  }
//  else if (currentPreset < 256) {
//    MIDI.sendControlChange(0, 1, midiChannel);
//    MIDI.sendProgramChange(currentPreset - 128, midiChannel);
//  }
//  else if (currentPreset < 383) {
//    MIDI.sendControlChange(0, 2, midiChannel);
//    MIDI.sendProgramChange(currentPreset - 256, midiChannel);
//  }
//}

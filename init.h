const unsigned char introSpeed = 12; //Lower value means faster intro, because that value determines the length of the pauses between LEDs

//Here I define custom symbols for the intro. I chose to display a sine wave (or is it a cosine wave?), which should be displayed as smoothly as possible. 8 symbols are available, so for every step of pi/2 I use one character on the display and two symbols.
unsigned char sinus1[8] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00001000,
  0b00011000,
  0b00010000,
  0b00010000,
};
unsigned char sinus2[8] = {
  0b00000011,
  0b00000110,
  0b00000100,
  0b00001100,
  0b00001000,
  0b00011000,
  0b00010000,
  0b00010000,
};
unsigned char sinus3[8] = {
  0b00011000,
  0b00001100,
  0b00000100,
  0b00000110,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
};
unsigned char sinus4[8] = {
  0b00011000,
  0b00001100,
  0b00000100,
  0b00000110,
  0b00000010,
  0b00000011,
  0b00000001,
  0b00000001,
};
unsigned char sinus5[8] = {
  0b00010000,
  0b00010000,
  0b00011000,
  0b00001000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
};
unsigned char sinus6[8] = {
  0b00010000,
  0b00010000,
  0b00011000,
  0b00001000,
  0b00001100,
  0b00000100,
  0b00000110,
  0b00000011,
};
unsigned char sinus7[8] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000110,
  0b00000100,
  0b00001100,
  0b00011000,
};
unsigned char sinus8[8] = {
  0b00000001,
  0b00000001,
  0b00000011,
  0b00000010,
  0b00000110,
  0b00000100,
  0b00001100,
  0b00011000,
};

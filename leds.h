const unsigned char numberOfLEDs = 10;

const unsigned char LED01 = 23;
const unsigned char LED02 = 25;
const unsigned char LED03 = 27;
const unsigned char LED04 = 29;
const unsigned char LED05 = 31;
const unsigned char LED06 = 33;
const unsigned char LED07 = 35;
const unsigned char LED08 = 47;
const unsigned char LED09 = 49;
const unsigned char LED10 = 51;

const unsigned char LEDBPM = 53; //This is the tempo LED

const unsigned char leds[numberOfLEDs] = {LED01, LED02, LED03, LED04, LED05, LED06, LED07, LED08, LED09, LED10};
bool ledState[numberOfLEDs];

unsigned long ledLastTime[numberOfLEDs];
const unsigned char ledLastTimeTimeout = 255;

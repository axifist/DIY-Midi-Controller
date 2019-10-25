bool tempoLedStatus = LOW;
unsigned long tempoLedLastTime = 0;

bool tunerStatus = false;
unsigned long tunerLastTime = 0;

unsigned char tunerFine = 0;

unsigned char *array = 0;
unsigned sysExSize;

const unsigned char lengthOfNoteNames = 3+1;
const char notesEnglishFlat[12][lengthOfNoteNames]  = {" A ", " Bb", " B ", " C ", " Db", " D ", " Eb", " E ", " F ", " Gb", " G ", " Ab"};
const char notesEnglishSharp[12][lengthOfNoteNames] = {" A ", " A#", " B ", " C ", " C#", " D ", " D#", " E ", " F ", " F#", " G ", " G#"};
const char notesGermanFlat[12][lengthOfNoteNames]   = {" A ", " B ", " H ", " C ", " Db", " D ", " Eb", " E ", " F ", " Gb", " G ", " Ab"};
const char notesGermanSharp[12][lengthOfNoteNames]  = {" A ", " B ", " H ", " C ", " C#", " D ", " D#", " E ", " F ", " F#", " G ", " G#"};
const char notesFrenchFlat[12][lengthOfNoteNames]   = {"LA ", "SIb", "SI ", "DO ", "REb", "RE ", "MIb", "MI ", "FA ", "SOb", "SO ", "LAb"};
const char notesFrenchSharp[12][lengthOfNoteNames]  = {"LA ", "LA#", "SI ", "DO ", "DO#", "RE ", "RE#", "MI ", "FA ", "FA#", "SO ", "SO#"};

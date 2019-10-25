const unsigned char numberOfGigs = 3;
const unsigned char maximumNumberOfSongsInGigs = 12;
const unsigned char numberOfGigInfos = 1; //1. number of songs

const unsigned char gigs[numberOfGigs] = {0, 1, 2}; //for the menu
const unsigned char sizeOfGigNames = 15;
const char nameOfGig[numberOfGigs][sizeOfGigNames] = { //Here the gigs get names
  "Gig 1 01.02.03",
  "Gig 2 04.05.06",
  "Gig 3 07.08.09",
};
const unsigned char gigSongs[numberOfGigs][maximumNumberOfSongsInGigs] = { //and here they are configured. Which songs will be played at which gig?
  //Gig 1
  {1, 2},
  //Gig 2
  {2, 1},
  //Gig 3
  {1, 2},
};

const unsigned char gigInfos[numberOfGigs] = { //For the Arduino to know when we reach the last song of the setlist, I need to tell it how many songs there are on this list. Could also be done with sizeof or something. TODO: see if sizeof is a good alternative to this. gigInfos is only called twice in songs_functions.h
  //Gig 1
  2,
  //Gig 2
  2,
  //Gig 3
  2,
};

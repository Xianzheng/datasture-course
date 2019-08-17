#ifndef _readfile_
#define _readfile_

typedef struct readfile{
  char keywords[13];
  char sentence[100];//patient ID
  float userRate;
  float systemRate;
  float learnRate;
  int times;
} Read;

int read(char *filename, Read *info);
#endif

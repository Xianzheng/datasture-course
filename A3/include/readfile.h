#ifndef _readfile_
#define _readfile_

typedef struct readfile{
  char words[100];//patient ID
} Read;

int read(char *filename, Read *info);
#endif

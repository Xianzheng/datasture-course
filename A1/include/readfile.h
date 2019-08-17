#ifndef _readfile_
#define _readfile_

typedef struct readfile{
  char prior;
  char proceed;
  int ontime;
} Read;

int read(char *filename, Read *info);
int sort(const void* a, const void *b);
#endif

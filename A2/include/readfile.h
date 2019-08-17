#ifndef _readfile_
#define _readfile_

typedef struct readfile{
  char id[100];//patient ID
  int pri;//priority
  char tom[100];//symptom
} Read;

int read(char *filename, Read *info);
int sort(const void* a, const void *b);
#endif

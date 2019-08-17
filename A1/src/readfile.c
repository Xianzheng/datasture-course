#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

int sort(const void* a, const void *b)
{
  const struct readfile *ia = (struct readfile *)a;
  const struct readfile *ib = (struct readfile *)b;
  return ia->ontime-ib->ontime;
}


int read(char *filename, Read *info)
{

  FILE *fp=fopen(filename,"r");

  int i=0;
  if(fp==NULL){
    printf("error by opening\n");
    exit(1);
  }


  while(fscanf(fp,"%c %c %d\n",&(info+i)->prior,&(info+i)->proceed,&(info+i)->ontime)!=EOF){
    i++;
  }

  qsort ( info, i, sizeof(Read), &sort);

  return i;
}

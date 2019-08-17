#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"


int read(char *filename, Read *info)
{
  FILE *fp=fopen(filename,"r");

  int i=0;
  //int z=0,option=0;
  if(fp==NULL){
    printf("error by opening\n");
    exit(1);
  }

  while(fscanf(fp,"%s \n",((info+i)->words))!=EOF){
    i++;
  }


  return i;
}

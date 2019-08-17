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

  /*while(fscanf(fp,"%s \n",((info+i)->words))!=EOF){
    i++;
  }*/

  while (1)
  {
    if (fgets((info+i)->keywords,13, fp) == NULL)
    {
      break;
    }
    if(fgets((info+i)->sentence, 100, fp) == NULL)
    {
      break;
    }
    (info+i)->userRate=0.5;
    (info+i)->systemRate=0.05;
    (info+i)->learnRate=0.5;
    (info+i)->times=0;
    i++;
  }


  return i;
}

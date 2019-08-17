#include <stdlib.h>
#include <stdio.h>
#include "LinkedListAPI.h"
#include "readfile.h"
#include "stimulator.h"
#include "API.h"


int main(int argc, char *argv[]){

  char *filename=argv[1];
  int size=0,i=0;
  Read *info=malloc(sizeof(Read)*100);

  size=read(filename,info);

  List *Queue=initializeList(&printFunction,&deleteFunction,&compareFunction);

  for(i=0;i<size;i++)
  insertBack(Queue,(info+i));
  printBackwards(Queue);
  simulator(Queue);

  free(info);
  free(Queue);
}

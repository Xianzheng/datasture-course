#include <stdlib.h>
#include <stdio.h>
#include "LinkedListAPI.h"
#include "readfile.h"
#include "stimulator.h"
#include "API.h"


int main(int argc, char *argv[]){

  char *filename=argv[1];
  int size=0,i=0,n=0,s=0,w=0,e=0;
//  List *list=initializeList(&printFunction,&deleteFunction,&compareFunction);

  Read *info=malloc(sizeof(Read)*100);
  size=read(filename,info);

  List *north=initializeList(&printFunction,&deleteFunction,&compareFunction);
  List *south=initializeList(&printFunction,&deleteFunction,&compareFunction);
  List *west=initializeList(&printFunction,&deleteFunction,&compareFunction);
  List *east=initializeList(&printFunction,&deleteFunction,&compareFunction);

  Node *node=malloc(sizeof(Node)*size);
  Node *n_north=malloc(sizeof(Node)*size);
  Node *n_south=malloc(sizeof(Node)*size);
  Node *n_west=malloc(sizeof(Node)*size);
  Node *n_east=malloc(sizeof(Node)*size);


  for(i=0;i<size;i++){
    (node+i)->data=(info+i);
    if(((Read*)(node+i)->data)->prior=='N') {
      //n_north[i]=(Node)malloc(sizeof(Node));
      n_north[n]=node[i];
      n++;
    }
    if(((Read*)(node+i)->data)->prior=='S') {
      n_south[s]=node[i];
      s++;
    }
    if(((Read*)(node+i)->data)->prior=='W') {
      n_west[w]=node[i];
      w++;
    }
    if(((Read*)(node+i)->data)->prior=='E') {
      n_east[e]=node[i];
      e++;
    }

  }
  //printf("a");
  for(i=0;i<n;i++)
  insertBack(north,(n_north+i));
  for(i=0;i<s;i++)
  insertBack(south,(n_south+i));
  for(i=0;i<w;i++)
  insertBack(west,(n_west+i));
  for(i=0;i<e;i++)
  insertBack(east,(n_east+i));
  printForward(south);
  simulator(north,south,west,east);

  free(node);
  free(n_north);
  free(n_west);
  free(n_south);
  free(n_east);
  free(north);
  free(south);
  free(west);
  free(east);

}

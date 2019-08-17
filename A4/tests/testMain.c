#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BinarySearchTreeAPI.h"
#include "API.h"
#include "readfile.h"


int main(int argc, char *argv[]){


  char *filename=argv[1];

  int i=0,z=0;
  Read *info=malloc(sizeof(Read)*100);
  z=read(filename,info);

  Tree *tree= createBinTree(compareFunction,deleteFunction);
  printf("Before addToTree\n");
  if(isTreeEmpty(tree)==1){
    printf("This tree is empty\n");
  }else{
    printf("This tree is not empty\n");
  }

  for(i=0;i<z;i++)
  addToTree(tree, (info+i));
  travel_data(tree);
  printf("\n");
  printf("Remove the second data\n");
  removeFromTree(tree,(info+1));
  travel_data(tree);


  /*print();
  while(1){
    //getchar();
    printf("Please enter your command:\n");
    fgets(command,sizeof(command),stdin);

    if(strcmp("1",command)==0){
        getchar();
        printf("Enter the keywords:\n");
        fgets(key,sizeof(key),stdin);
        printf("Enter the sentence:\n");
        fgets(sentence,sizeof(sentence),stdin);
        printf("Enter the rate:\n");
        scanf("%f",&frate);

        strcpy((info+z)->keywords,key);
        strcpy((info+z)->sentence,sentence);
        (info+z)->userRate=frate;
        (info+z)->systemRate=0.05;
        (info+z)->learnRate=frate;
        (info+z)->times=0;
        addToTree(tree, (info+z));
        getchar();
      }
    if(strcmp("2",command)==0)
    {
      int k;
      getchar();
      printf("Enter a keywords you want to remove:\n");
      fgets(key,sizeof(key),stdin);
      printf("%s",key);
      k=searchInRead(z,key,info);
      if(k>=0){
       removeFromTree(tree,(info+k)->keywords);
       memset((info+k)->keywords,0,sizeof(info+k));
      }else{
       printf("No Data Was Found\n");
      }

    }
    if(strcmp("3",command)==0)
    {
      travel_data(tree);
      getchar();
    }
    if(strcmp("4",command)==0)
    {
      int k=0;
      getchar();
      printf("Enter a keywords you want to search:\n");
      fgets(key,sizeof(key),stdin);
      k=searchInRead(z,key,info);
      if(k>=0){
       printf("Key was found, enter the new user Rate\n");
       scanf("%f",&frate);
       printf("%f",frate);
       (info+k)->userRate=frate;
      }else{
       printf("No Data Was Found\n");
      }
    }
    if(strcmp("5",command)==0){
      int k=0;
      int i=0;
      getchar();
      printf("Enter a sentence you want to talk:\n");
      fgets(sentence,sizeof(sentence),stdin);
      char *token=strtok(sentence," ");
      while(token){
      //  printf("%s\n",token);
        for(i=0;i<=z;i++){
          if(strcmp(token,(info+i)->keywords)==0){
            k=i;
          }
        }
        token=strtok(NULL," ");
      }
        printf("feedBack: %s\n",(info+k)->sentence);
        (info+k)->times++;
        float sr=(info+k)->systemRate;
        float u=(info+k)->userRate;
        float t=(info+k)->times;
        printf("Is this feedBack Helfful(y or n)\n");
        scanf("%s",feedBack);
        if(strcmp("y",feedBack)==0){
          sr+=(sr*u/t);
          (info+k)->systemRate=sr;
        }
        if(strcmp("n",feedBack)==0){
          sr-=(sr*u/t);
          (info+k)->systemRate=sr;
        }
        getchar();
    }

  }
//  removeFromTree(tree,(info+1)->keywords);

  //Tree *tempt=findInTree(tree,(info+1)->keywords);
    //printf("%s",((Read*)tempt->root)->sentence);
    //removeFromTree(tree,(info+3)->keywords);
    //travel_data(tree);


*/
}
//```````````````~~~~~~~~~~~~~~~~

#include "HashTableAPI.h"
#include <stdio.h>
#include <string.h>
#include <readfile.h>
int hashFunction(size_t tableSize, int key){
  return 1;
}
void destroyData(void *data){

}
void printNode(void *toBePrinted){

}
void printManu(){
  printf("1)  Add a word to Dictionary\n");
  printf("2)  Remove a word from Dictionary\n");
  printf("3)  Spell Check a file\n");
  printf("4)  show Dictionary Words\n");
  printf("5)  Quit");
  printf("\n");
}

int main(int argc, char *argv[]){
  char *filename=argv[1];
  HTable *Htable=createTable(52,&hashFunction,&destroyData,&printNode);
  Read *info=malloc(sizeof(Read)*100);
  Read *user=malloc(sizeof(Read)*100);
  int enter,key,count=0;
  int size_d=read("./bin/dictionary.txt",info);
  int size_u=read(filename,user);
  char word[100];
//  printf("%d",size_d);

  int i=0, j=0;
  for(j=2;j<=size_d+1;j++){
  insertData(Htable,j,(info+j-2)->words);
  }
  //size_d=21;
 printManu();

  while(1){
    printf("Please enter integer(1.add 2.remove 3.check 4.show 5.quit):\n");
    scanf("%d",&enter);
    if(enter==1){
      printf("please enter the word you want to add to dictionary\n");
      scanf("%s",word);
      size_d++;
      insertData(Htable,size_d,word);
    }
    if(enter==2){
      printf("please enter the key of word you want to remove\n");
      scanf("%d",&key);
      removeData(Htable,key);
    }
    if(enter==3){
    for(j=0;j<size_u;j++){
      for(i=0;i<Htable->size;i++){
        if(Htable->table[i]){
          Node *p=Htable->table[i];
          //printf("hash:%d=>",i);
          while(p){

              if(strcmp((user+j)->words,(char*)p->data)==0){
              count++;
              printf("%s   was  found in the dictionary\n",(char*)p->data);
              }

              p=p->next;
          }

        }
      }


    }
    printf("Summary:\n" );
    printf("correct spelt words:%d\n",count);
    printf("incorrect spelt words:%d\n",size_u-count);
    }
    if(enter==4){
      printcontent(Htable);
    }
    if(enter==5){
      destroyTable(Htable);
      break;
    }
  }



}

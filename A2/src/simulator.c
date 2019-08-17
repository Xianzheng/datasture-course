#include "LinkedListAPI.h"
#include "readfile.h"
#include <string.h>

int ProceedTime(Node *p){
  if(strcmp(((Read*)p->data)->tom,"CV")==0){
    return 5;
  }else
  if(strcmp(((Read*)p->data)->tom,"HN")==0){
    return 3;
  }else
  if(strcmp(((Read*)p->data)->tom,"EV")==0){
  return 10;
  }else
  if(strcmp(((Read*)p->data)->tom,"GI")==0){
    return 2;
  }else
  if(strcmp(((Read*)p->data)->tom,"MH")==0){
    return 5;
  }else
  if(strcmp(((Read*)p->data)->tom,"NC")==0){
  return 5;
  }else
  if(strcmp(((Read*)p->data)->tom,"EC")==0){
    return 1;
  }else
  if(strcmp(((Read*)p->data)->tom,"RC")==0){
    return 1;
  }else
  if(strcmp(((Read*)p->data)->tom,"SK")==0){
  return 2;
  }else
  if(strcmp(((Read*)p->data)->tom,"SA")==0){
    return 7;
  }else
  if(strcmp(((Read*)p->data)->tom,"TR")==0){
    return 4;
  }
  else
  return 0;
}

void print(Node *p,int complete){
  printf("%s\t\t%d\t\t%s\t\t%d\n",((Read*)p->data)->id,((Read*)p->data)->pri,((Read*)p->data)->tom,complete);
}


void simulator(List *Queue){
  char *Info1="Patient ID";
  char *Info2="Priority";
  char *Info3="Symptom Code";
  char *Info4="Time Finished";
//  float R=1, F=2, L=2.5;
  Node *n=Queue->head;


  printf("%s\t%s    %s    %s\n",Info1,Info2,Info3, Info4);

  while(n->next!=NULL){
    static int priorFinishTime=0;
    static int completedTime=0;
    static int z=0;
    int paperWork=1;
    Node *n=Queue->head;
    n=n->next;
    if(z==0){
      completedTime+=paperWork+ProceedTime(n);
    //  printf("%d",completedTime);
      priorFinishTime=completedTime;
    }else {
      completedTime=priorFinishTime+ProceedTime(n)+paperWork;
      priorFinishTime=completedTime;
    }

    print(n,completedTime);
    deleteNodeFromList(Queue,n);
    z++;
  }


 }//big loop

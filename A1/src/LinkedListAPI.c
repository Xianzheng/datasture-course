#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "readfile.h"

Node *initializeNode(void *data){
  Node *node=malloc(sizeof(Node));
  if(node!=NULL){
  //  node->data==NULL;
    node->next=NULL;
    node->previous=NULL;
  }
  return node;
}

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
  List *list =malloc(sizeof(list));
  Node* head =initializeNode(NULL);

  if(list!=NULL){
    if(head!=NULL) {
      list->head=head;
      list->tail=head;
    }
  }else{
    return NULL;
  }
  return list;

}

void insertFront(List *list, void *toBeAdded){

  Node *head =list->head;
  if(head->next!=NULL)
  head->next->previous=toBeAdded;
  ((Node *)toBeAdded)->next=head->next;
  ((Node *)toBeAdded)->previous=head;
  head->next=toBeAdded;

}

void insertBack(List *list, void *toBeAdded){
  Node *temp=list->head;
  while(temp->next!=NULL)
  temp=temp->next;
  temp->next=toBeAdded;
  ((Node *)toBeAdded)->previous=temp;
}


void printForward(List *list){
  Node *p=list->head;
  while(p->next!=NULL){
      p=p->next;
      printf("%c %c %d\n",((Read*)p->data)->prior,((Read*)p->data)->proceed,((Read*)p->data)->ontime);
  }
}

void printBackwards(List *list){
  Node *p=list->head;
//  printf("%s",p);
  while(p->next!=NULL){
    p=p->next;
  }
  while(p->previous!=NULL){
    printf("%c %c %d\n",((Read*)p->data)->prior,((Read*)p->data)->proceed,((Read*)p->data)->ontime);
    p=p->previous;
  }
}

int deleteNodeFromList(List *list, void *toBeDeleted){
  int i=0,size=0;
  Node *p=list->head;
  Node *s=list->head;

  while(s->next!=NULL){
    s=s->next;
    size++;
  }
  if(p->next->next==NULL){
    p->previous=list->head;
    list->head->next=NULL;
    memset(p,0,sizeof(Node));
  }

  while(p->next!=NULL){
    p=p->next;
    if(p==(Node*)toBeDeleted){
      if(i==0){
      //  printf("%d\n",i);
        list->head->next=p->next;
        p->next->previous=list->head;
        memset(p,0,sizeof(Node));
      }
      if(i>0&&i<size-1){
      //printf("%d\n",i);
      p->next->previous=p->previous;
      p->previous->next=p->next;
      memset(p,0,sizeof(Node));
    }if(i==size-1){
      //  printf("%d\n",i);
        Node *q=p;
        p=p->previous;
        p->next=NULL;
        memset(q,0,sizeof(Node));
      }
    }
    i++;
  }
  return 1;
}

void deleteList(List *list){
  int i=0;
  for(i=0;i<3;i++){
  Node *p=list->head;
  p=p->next;
  p->next->previous=p->previous;
  list->head->next=NULL;
  memset(p,0,sizeof(Node));
  }
  Node *p=list->head;
  p=p->next;
  p->previous=list->head;
  list->head->next=NULL;
  memset(p,0,sizeof(Node));
}

void *getFromFront(List *list){
  Node *p=list->head;
  p=p->next;
  return p;
  //printf("%c %c %d\n",((Read*)p->data)->prior,((Read*)p->data)->proceed,((Read*)p->data)->ontime);
}

void *getFromBack(List *list){
  Node *p=list->head;

  while(p->next!=NULL){
    p=p->next;
  }
  return p;
  //printf("%c %c %d\n",((Read*)p->data)->prior,((Read*)p->data)->proceed,((Read*)p->data)->ontime);
}

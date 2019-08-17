#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "readfile.h"

Node *initializeNode(void *data){
  Node *node=malloc(sizeof(Node));
  if(node!=NULL){
    node->data=data;
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
  Node *new =initializeNode(toBeAdded);
  Node *head =list->head;
  if(head->next!=NULL)
  head->next->previous=toBeAdded;
  new->next=head->next;
  new->previous=head;
  head->next=new;
}

void insertBack(List *list, void *toBeAdded){
  Node *new=initializeNode(toBeAdded);
  Node *temp=list->head;
  while(temp->next!=NULL)
  temp=temp->next;
  temp->next=new;
  new->previous=temp;
}


void printForward(List *list){
  Node *p=list->head;
  while(p->next!=NULL){
      p=p->next;
      printf("%s %d %s\n",((Read*)p->data)->id,((Read*)p->data)->pri,((Read*)p->data)->tom);
  }
}

void printBackwards(List *list){
  Node *p=list->head;
  while(p->next!=NULL){
    p=p->next;
  }
  while(p->previous!=NULL){
      printf("%s %d %s\n",((Read*)p->data)->id,((Read*)p->data)->pri,((Read*)p->data)->tom);
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
    free(p);
  }

  while(p->next!=NULL){
    p=p->next;
    if(p==(Node*)toBeDeleted){
      if(i==0){
        list->head->next=p->next;
        p->next->previous=list->head;
        free(p);
      }
      if(i>0&&i<size-1){
      p->next->previous=p->previous;
      p->previous->next=p->next;
      free(p);
    }if(i==size-1){
        Node *q=p;
        p=p->previous;
        p->next=NULL;
        free(q);
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
void insertSorted(List *list, void *toBeAdded){
  Node *p=list->head->next;
  if(((Read*)(Node*)toBeAdded)->pri < ((Read*)p->data)->pri)
  insertFront(list,toBeAdded);
}

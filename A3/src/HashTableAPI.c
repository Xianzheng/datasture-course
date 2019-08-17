#include "HashTableAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted))
{

  HTable *ht=malloc(sizeof(HTable));
  if(NULL==ht){
  printf("failed create table");
  return NULL;
  }
  ht->table=malloc(sizeof(Node)*size);
  if(NULL==ht->table){
  printf("failed create table");
  return NULL;
  }
  ht->size=size;
  return ht;
}

Node *createNode(int key, void *data){
  Node *node=malloc(sizeof(Node));
  node->next=NULL;
  node->key=key;
  node->data=data;
  return node;
}

int hashNode(size_t tableSize, int key){
  int hash;
  int i=0;
  while(hash<ULONG_MAX&&i<key){
    hash=hash<<8;
    hash+=key;
    i++;
  }
  return hash % tableSize;
}

void insertData(HTable *hashTable, int key, void *data){
//  printf("%d\n",key);
 int i=0;
  i=  hashNode(hashTable->size, key);
  //printf("%d\n",i);
  Node *p=hashTable->table[i];
  while(p){
    //printf("dfsafds");
    if(p->key==key){
      free(p);
      Node *new=createNode(key,data);
      hashTable->table[i]=new;
      return;
    }
    printf("fdadf\n");
    p=p->next;
  }

  Node *new=createNode(key,data);
  //free(new->data);
  //new->data=malloc(sizeof(Node));

  hashTable->table[i]=new;



}
void *lookupData(HTable *hashTable, int key){
  //printf("254");

  int i=hashNode(hashTable->size,key);
//  Node* p=hashTable->table[i];
  if(hashTable->table[i]){
    Node *p=hashTable->table[i];
    while(p){
      //printf("a");
      if(p->key==key){
       return p->data;

      }
      p=p->next;
    }
    return NULL;
  }
  return NULL;
}

void removeData(HTable *hashTable, int key){
  int i=i=hashNode(hashTable->size,key);
  Node *p=hashTable->table[i];
  Node *pop=p;
  while(p){
    if(key==p->key){
      free(p);
      if(p==pop){
        hashTable->table[i]=NULL;
      }else{
        pop->next=p->next;
      }
      break;
    }
    pop=p;
    p=p->next;
  }
}
void printcontent(HTable *hashTable){
  int i;
  for(i=0;i<hashTable->size;i++){
    if(hashTable->table[i]){
      Node *p=hashTable->table[i];
      printf("hash:%d=>",i);
      while(p){
        printf("key:%d: %s",p->key,(char*)p->data);
        p=p->next;
      }
      printf("\n");
    }
  }
}


void destroyTable(HTable *hashTable){
  int i;
  for(i=0;i<hashTable->size;i++){
    if(hashTable->table[i]){
      Node *p=hashTable->table[i];
      //printf("hash:%d=>",i);
      while(p){
        Node *q=p;
        p=p->next;
        if(q){
          free(q);
        }
      }
    //  printf("\n");
    }
  }
  free(hashTable);
}

#include "LinkedListAPI.h"
#include "readfile.h"
#include <string.h>

float ProceedTime(Node *p){
  if(((Read*)p->data)->proceed== 'R'){
    return 1.0;
  }
  if(((Read*)p->data)->proceed== 'F'){
    return 2.0;
  }
  if(((Read*)p->data)->proceed== 'L'){
  return 2.5;
  }
  else
  return 0;
}

float ArriveTime(Node *p){
  return ((Read*)p->data)->ontime;
}

void print(Node *d,float time){
  printf("%c %c %d \t\t\t\t%d\t\t\t\t%.1f\n",((Read*)d->data)->prior,
  ((Read*)d->data)->proceed,((Read*)d->data)->ontime,
  ((Read*)d->data)->ontime, time);
}

void simulator(List *north, List *south, List *west, List *east){
  float periodTime=14;
  int i=-1;
  float completedTime=0;
  char *Info1="Initial Vehicle information";
  char *Info2="Intersection Arrival Time";
  char *Info3="Completed at Time";
//  float R=1, F=2, L=2.5;
  Node *n=north->head;
  Node *s=south->head;
  Node *e=east->head;
  Node *w=west->head;

  printf("%s   %s   %s\n",Info1,Info2,Info3);
while(n->next!=NULL||e->next!=NULL||s->next!=NULL||w->next!=NULL){
  //direction : N
  i++;
  while(n->next!=NULL){
    static int z=0;
    static float priorArriveTime=0;
    Node *n=north->head;
    n=n->next;
    if(((Read*)n->data)->ontime>periodTime*i&&((Read*)n->data)->ontime<periodTime*(i+1)){//if arriving time is bigger than last run end
      if(i==0)
      completedTime=+ProceedTime(n)+ArriveTime(n);
      if(i>0)
      completedTime=completedTime+ProceedTime(n);

    }else{
       if(z==0){
        priorArriveTime=ProceedTime(n)+periodTime*i;//the time of last run end+first run
        if(((Read*)n->data)->ontime>periodTime*(i+1)) {
          z=0;
          break;
        }
        completedTime=priorArriveTime;
       }else{
         completedTime=+ProceedTime(n)+completedTime;
         if(((Read*)n->data)->ontime>periodTime*(i+1)) {
           z=0;
           break;
         }
       }
    }
    print(n,completedTime);
    deleteNodeFromList(north,n);
    z++;
  }
  //direction:E
  i++;
  while(e->next!=NULL){
    static int z=0;
    static float priorArriveTime=0;
    Node *e=east->head;
    e=e->next;
    if(((Read*)e->data)->ontime>periodTime*i&&((Read*)e->data)->ontime<periodTime*(i+1)){//if arriving time is bigger than last run end
      if(i==1)
      completedTime=+ProceedTime(e)+ArriveTime(e);
      if(i>1)
      completedTime=completedTime+ProceedTime(e);
    }else{
       if(z==0){
        priorArriveTime=ProceedTime(e)+periodTime*i;//the time of last run end+first run
        if(((Read*)e->data)->ontime>periodTime*(i+1)) {
          z=0;
          break;
        }
        completedTime=priorArriveTime;
       }else{
         completedTime=ProceedTime(e)+completedTime;
         if(((Read*)e->data)->ontime>periodTime*(i+1)) {
           z=0;
           break;
         }
       }
    }
    print(e,completedTime);
    deleteNodeFromList(east,e);
    z++;
  }

  //direction: S
  i++;
  while(s->next!=NULL){
    static int z=0;
    static float priorArriveTime=0;
    Node *s=south->head;
    s=s->next;
    if(((Read*)s->data)->ontime>periodTime*i&&((Read*)s->data)->ontime<periodTime*(i+1)){//if arriving time is bigger than last run end
      if(i==2)
      completedTime=+ProceedTime(s)+ArriveTime(s);
      if(i>2)
      completedTime=completedTime+ProceedTime(s);
    }else{
       if(z==0){
        priorArriveTime=ProceedTime(s)+periodTime*i;//the time of last run end+first run
        if(((Read*)s->data)->ontime>periodTime*(i+1)) {
          z=0;
          break;
        }
        completedTime=priorArriveTime;
       }else{
         completedTime=+ProceedTime(s)+completedTime;
         if(((Read*)s->data)->ontime>periodTime*(i+1)) {
           z=0;
           break;
         }
       }
    }
    print(s,completedTime);
    deleteNodeFromList(south,s);
    z++;
  }
  //direction: W
  i++;
   while(w->next!=NULL){
     static int z=0;
     static float priorArriveTime=0;
     Node *w=west->head;
     w=w->next;
     if(((Read*)w->data)->ontime>periodTime*i&&((Read*)w->data)->ontime<periodTime*(i+1)){//if arriving time is bigger than last run end
       if(i==3)
       completedTime=completedTime+ProceedTime(w);
       if(i>3)
       completedTime=completedTime+ProceedTime(w);
     }else{
        if(z==0){
         priorArriveTime=ProceedTime(w)+periodTime*i;//the time of last run end+first run
         if(((Read*)w->data)->ontime>periodTime*(i+1)) {
           z=0;
           break;
         }
         completedTime=priorArriveTime;

        }else{
          completedTime=+ProceedTime(w)+completedTime;
          if(((Read*)w->data)->ontime>periodTime*(i+1)) {
            z=0;
            break;
          }
        }
      }

     print(w,completedTime);
     deleteNodeFromList(west,w);
     z++;
   }
 }//big loop


}//void end

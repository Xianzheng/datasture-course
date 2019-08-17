#include "BinarySearchTreeAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include "API.h"
#include "readfile.h"

Tree * createBinTree(CompareFunc compare, DeleteFunc del){
  Tree *tree=malloc(sizeof(Tree));
  return tree;
}

TreeNode* createTreeNode(TreeDataPtr data){

  TreeNode *node=(TreeNode *)malloc(sizeof(TreeNode));
  if(node){
    node->data=data;
    node->left=NULL;
    node->right=NULL;
  }
  return node;
}
void insert(TreeNode** pRoot, TreeNode *pn){
  if(NULL == *pRoot){
    *pRoot = pn;
    return;
  }
  if((*pRoot)->data>pn->data){
    insert(&(*pRoot)->left,pn);
  }else{
    insert(&(*pRoot)->right,pn);
  }
}
void addToTree(Tree * theTree, TreeDataPtr data){
  insert(&(theTree)->root,createTreeNode(data));
}
void travel(TreeNode *pRoot){
  if(pRoot!=NULL){
    travel(pRoot->left);
    printf("%s Rating:%.2f System:%.2f Occurrences:%d\n",((Read*)pRoot->data)->keywords,((Read*)pRoot->data)->userRate,((Read*)pRoot->data)->systemRate,((Read*)pRoot->data)->times);
    travel(pRoot->right);
  }
}
void travel_data(Tree *pt){
  travel(pt->root);
  //printf("\n");
}
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data ){
  if(NULL==theTree->root)
  return theTree->root;

  if(data==theTree->root->data)
  return theTree->root;

  while((theTree->root!=NULL&&(theTree->root->data!=data))){
    if(data<theTree->root->data)
    theTree->root=theTree->root->left;
    else
    theTree->root=theTree->root->right;
  }
  return theTree->root;
}
void removeFromTree(Tree * theTree, TreeDataPtr data){
  TreeNode *p=theTree->root;
  TreeNode *parent=NULL;
  TreeNode *s;
  TreeNode *ps;
  while(p!=NULL&&data!=p->data){
    parent=p;
    if(p->data>data)
    p=p->left;
    else
    p=p->right;

  }

  if(p==NULL)
  //delete left node;
  printf("no Node");
  if(p->left==NULL&&p->right==NULL)
  {
    if(parent==NULL)
    theTree->root=NULL;
    else if(parent->left==p)
    parent->left=NULL;
    else
    parent->right=NULL;
  }
  //delete node has left child
  else if(p->left!=NULL&&p->right==NULL)
  {
    if(parent==NULL)
    theTree->root=p->left;
    else if(parent->right==p)
    parent->right=p->left;
    else
    parent->left=p->left;
  }
  //delete node has right child
  else if(p->left==NULL&&p->right!=NULL)
  {
    if(parent==NULL){
      theTree->root=p->right;
    }else if(parent->right==p)
    parent->right=p->right;
    else
    parent->left=p->right;
  }
  //deletenode has both
  else{
    ps=p;
    s=p->left;
    while(s->right!=NULL){
      ps=s;
      s=s->right;
    }
    if(p==NULL){
      theTree->root=s;
    }else if(parent->left==p){
      parent->left=s;
    }else{
      parent->right=s;
    }
    s->right=p->right;
    if(ps!=p){
      s->left=p->left;
      if(ps->left==s){
        ps->left=s->left;
      }
      else{
        ps->right=s->left;
      }
    }
  }

}
void  destroyBinTree(Tree * toDestroy){
  TreeNode *top=NULL;
  TreeNode *temp, *q;
  temp=toDestroy->root->left;
  toDestroy->root->left=top;
  top=toDestroy->root;
  while(top!=NULL)
  {
    while(temp!=NULL){
      q=temp;
      temp=q->left;
      q->left=top;
      top=q;
    }
    temp=top;
    if(temp->right!=NULL){
      q=temp;
      temp=q->right;
      q->right=NULL;
    }
    else{
      top=temp->left;
      free(temp);
      temp=NULL;
    }
  }
  toDestroy->root=NULL;
}
TreeDataPtr getRootData(Tree * t){
  return t->root->data;
}
int isTreeEmpty(Tree* theTee){
  if(theTee)
  return 1;
  else
  return 0;
}
int isLeaf( TreeNode * treeNode){
  if(treeNode->left||treeNode->right)
  return 1;
  else
  return 0;
}
int hasTwoChildren( TreeNode *treeNode){
  if(treeNode->left&&treeNode)
  return 1;
  else
  return 0;
}

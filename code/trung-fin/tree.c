#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"
tree createTree(){
  return NULL;
}
int isNullTree(tree t) {
  return (t == NULL);
}
void makeNULLTree(tree *t){
    if((*t) == NULL) return;
    makeNULLTree(&(*t)->left);
    makeNULLTree(&(*t)->right);
    free((*t));
}
element_t createData(char id[],char name[],int accumulated,int numElec,int numFashion,int elecPayment,int fashionPayment){
  element_t n = (element_t) malloc(sizeof(struct Node));
  strcpy(n->name,name);
  strcpy(n->id,id);
  n->accumulated = accumulated;
  n->numsElectronic = numElec;
  n->numsFashion = numFashion;
  n->electronicPayment = elecPayment;
  n->fashionPayment = fashionPayment;
  return n;
}
tree createNewNode(element_t x){
  treeNode newNode = (treeNode) malloc(sizeof(struct Tree));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = x;
  return newNode;
}
tree leftNode(tree t){
  if (t == NULL) return t;
  return leftNode(t->left);
}
tree rightNode(tree t){
  if (t == NULL) return t;
  return rightNode(t->left);
}
// addRightMost and addLeftMost For normal Tree
tree addLeftMost(tree t,treeNode x){
  while(t->left != NULL)
    t = t->left;
  t->left = x;
  return t;
}
tree addRightMost(tree t,treeNode x){
  while(t->right != NULL)
    t = t->right;
  t->right = x;
  return t;
}
int countNode(tree t){
  if (t == NULL) return 0;
  return 1 + countNode(t->right) + countNode(t->left);
}
int heightTree(tree t){
if (t==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = heightTree(t->left); 
       int rDepth = heightTree(t->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}
int isLeaf(tree t){
  return (t->left == NULL && t->right == NULL);
}
int countLeaf(tree t){
  if(t == NULL) return 0;
  if(t->left != NULL || t->right != NULL) return 0 + countLeaf(t->left) + countLeaf(t->right);
  return 1;
}
int countInnerNode(tree t){
    if(t == NULL) return 0;
    if(t->left != NULL || t->right != NULL) return 1 + countInnerNode(t->right) + countInnerNode(t->left);
    else return 0;
}
int rightChildCount(tree t) {
  if(t == NULL) return 0;
  return 1 + rightChildCount(t->right);
}
tree search(tree t ,keyvalue x){
  if (t == NULL) return NULL;
  if( strcmp(x->id,t->data->id) > 0 ){
      return search(t->right,x);
  }else if( strcmp(x->id,t->data->id) < 0 ){
      return search(t->left,x);
  }
  return t;
}
void insertSameID(tree t,keyvalue x){
    t->data->accumulated += x->accumulated;
    t->data->electronicPayment += x->electronicPayment;
    t->data->fashionPayment += x->fashionPayment;
    t->data->numsElectronic += x->numsElectronic;
    t->data->numsFashion += x->numsFashion;
}
void insert(tree *t,keyvalue x){
   if((*t) == NULL){
        (*t) = createNewNode(x);
        return;
    }
    else if(strcmp(x->id,(*t)->data->id) < 0)
        insert(&(*t)->left,x);
    else if(strcmp(x->id,(*t)->data->id) > 0)
        insert(&(*t)->right,x);
    else{
        insertSameID((*t),x);
    }
}
tree  minValueNode(tree node) 
{ 
    tree current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
tree deleteNode(tree root,keyvalue x){
        if (root == NULL) return root;
    if(strcmp(x->id,root->data->id) < 0){
        root->left = deleteNode(root->left,x);
    }else if(strcmp(x->id,root->data->id) > 0){
        root->right = deleteNode(root->right,x);
    }else{
        if(root->left == NULL){
            tree temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            tree temp = root->left;
            free(root);
            return temp; 
        }else{
            tree temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
}

tree findMin(tree t){
  return (t->left == NULL) ? t : findMin(t->left);
} 
tree findMax(tree t){
  return (t->right == NULL) ? t : findMin(t->right);
}
void traversal(tree t){
    if (t == NULL) return;
    traversal(t->left);
    printf("%-6s%-30s%-15d%-15d%d\n",t->data->id,t->data->name,t->data->accumulated,t->data->numsElectronic,t->data->numsFashion);
    traversal(t->right);
}
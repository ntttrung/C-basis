#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

 
tree createNullTree() {
  return (tree)NULL;
}

tree createTree(element_t x, tree l, tree r) {
  tree t = (tree)malloc(sizeof(struct TreeNode));
  t->data = x;
  t->left = l;
  t->right = r;
  return t;
}

tree createLeaf(element_t x) {
  return createTree(x, createNullTree(), createNullTree());
}

int isNullTree(tree t) {
  return (t == NULL);
}

int isLeaf(tree t) {
  return ((t != NULL) &&
	  (t->left == NULL) &&
	  (t->right == NULL)); 
}

int sizeOfTree(tree t) {
  if (isNullTree(t))
    return 0;
  else
    return (1 + sizeOfTree(t->left) + sizeOfTree(t->right));
}

int sumOfTree(tree t) {
  if (isNullTree(t))
    return 0;
  else
    return (t->data + sumOfTree(t->left) + sumOfTree(t->right));
}

char* treeToString(tree t) {
  char *result;
  char *left;
  char *right;
  
  if (isNullTree(t)) {
    result = (char*)malloc(4);
    strcpy(result, "Nil");
    return result;
  } else {
    left = treeToString(t->left);
    right = treeToString(t->right);
    
    result = (char*)malloc(40 + strlen(left) + strlen(right));
    sprintf(result, "node(%d,%s,%s)", t->data, left, right);
    free(left);
    free(right);
    return result;
  }
}

tree left(tree t) {
  if (isNullTree(t))
    return NULL;
  else return t->left;
}

tree right(tree t) {
  if (isNullTree(t))
    return NULL;
  else return t->right;
}

element_t value(tree t) {
  if (isNullTree(t))
    return 0;
  else return t->data;
}

struct TreeNode* leftMost(tree t) {
  struct TreeNode *n = t;
  
  if (isNullTree(t)) return NULL;
  while (!isNullTree(left(n)))
    n = left(n);
  return n;
}

struct TreeNode* rightMost(tree t) {
  struct TreeNode *n = t;
  
  if (isNullTree(t)) return NULL;
  while (!isNullTree(right(n)))
    n = right(n);
  return n;
}

tree addToLeftMost(tree t, element_t x) {
  tree n = leftMost(t);
  
  if (isNullTree(t))
    return createLeaf(x);
  else {
    n->left = createLeaf(x);
    return t;
  }
}

tree addToRightMost(tree t, element_t x) {
  tree n = rightMost(t);
  
  if (isNullTree(t))
    return createLeaf(x);
  else {
    n->right = createLeaf(x);
    return t;
  }
}

int height(tree t) {
  if(isNullTree(t)==1) return 0;
  if(height(t->left)>=height(t->right)) return 1+height(t->left);
  return 1+height(t->right);
  
}
int leavesCount(tree t) {
  if(isNullTree(t)==1) return 0;
  if((t->left==NULL)&&(t->right==NULL))
    return 1;
  return leavesCount(t->left)+leavesCount(t->right);
}
int innerNodeCount(tree t) {
  if(isNullTree(t)==1) return 0;
  if(t->left==NULL && t->right==NULL) return 0;
  if((t->left!=NULL)||(t->right!=NULL)) return 1+innerNodeCount(t->left)+innerNodeCount(t->right);
}
int rightChildCount(tree t) {
  // TODO
}

struct TreeNode *searchBST(tree t, element_t x) {
  if (isNullTree(t))
    return NULL;
  
  if (value(t) == x)
    return t;
  else if (value(t) < x)
    return searchBST(right(t), x);
  else
    return searchBST(left(t), x);
}

tree insertBST(tree t, element_t x) {
  if (isNullTree(t))
    return createLeaf(x);

  if (value(t) == x)
    return t;
  else if (value(t) > x) {
    t->left = insertBST(t->left, x);
    return t;
  } else {
    t->right = insertBST(t->right, x);
    return t;
  }
}
// xoa nut goc va tra ve cay BST sau khi da xoa
tree removeRootBST(tree t) {
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;
  // Xoa nut la
  if (isLeaf(t)) {
    free(t);
    return NULL;
  }
  // Xoa nut co 1 con phai
  if (left(t) == NULL) {
    tmp = right(t);
    free(t);
    return tmp;
  }
  // Xoa nut co 1 con trai
  if (right(t) == NULL) {
    tmp = left(t);
    free(t);
    return tmp;
  }
  // Xoa nut co hai con
  p = t;
  tmp = right(t);
  while (left(tmp) != NULL) {
    p = tmp;
    tmp = left(tmp);
  }

  t->data = tmp->data;
  tmp = removeRootBST(tmp);
  if (p == t)
    p->right = tmp;
  else
    p->left = tmp;
  return t;
}

tree removeBST(tree t, element_t x) {
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;

  if (t->data == x)
    return removeRootBST(t);

  p = NULL;
  tmp = t;
  while ((tmp != NULL) && (tmp->data != x)) 
    if (tmp->data > x) {
      p = tmp;
      tmp = tmp->left;
    } else {
      p = tmp;
      tmp = tmp->right;
    }

  if (tmp != NULL) {
    if (p->left == tmp) {
      p->left = removeRootBST(tmp);
    }
    else {
      p->right = removeRootBST(tmp);
    }
  }
  return t;
}

int countNode(tree t){
  if (t == NULL) return 0;
  return 1 + countNode(t->right) + countNode(t->left);
}

void freetree(tree t) 
  {
    if(isNullTree(t)!=1)
      {
        freetree(t->left);
        freetree(t->right);
        free((void *)t);
      }
  }

int IsEmpty(Queue *_Queue){
    return (_Queue->size == 0);
}
int IsFull(Queue *_Queue){
    return (_Queue->size == _Queue->limit);
}
Queue *CreateNewQueue(tree Root){
    Queue *newQueue = (Queue *) malloc(sizeof(Queue));
    newQueue->front = 0;
    newQueue->rear = 0;
    newQueue->size = 0;
    newQueue->limit = countNode(Root);
    newQueue->_Data = (tree) malloc(sizeof(struct TreeNode) * countNode(Root));
    return newQueue;
}

void enqueue(Queue **_Queue,tree Node){
    if(IsFull((*_Queue))) {
        printf("The queue is full\n");
        return;
    }
    (*_Queue)->_Data[(*_Queue)->rear] = (*Node);
    if((*_Queue)->rear + 1 < (*_Queue)->limit) (*_Queue)->rear +=1;
    else (*_Queue)->rear = 0;
    (*_Queue)->size += 1;
    return;
}   
tree Dequeue(Queue *_Queue){
    if(IsEmpty(_Queue)) {
        printf("The queue is empty\n");
        return NULL;
    }
    tree returnTree = (_Queue->_Data + _Queue->front );
    if(_Queue->front + 1 < _Queue->limit) _Queue->front +=1;
    else _Queue->front = 0;
    _Queue->size -= 1;
    return returnTree;
}
void breadth_first_search(tree Root){
    Queue *queue = CreateNewQueue(Root);
    tree RunNode = Root;
    if(RunNode != NULL){
        enqueue(&queue,RunNode);
        while(!IsEmpty(queue)){
            RunNode = Dequeue(queue);
            // fprintf(ptr,"%s %s",RunNode->data->word,RunNode->data->meaning);
            printf("%d",RunNode->data);
            if(RunNode->left != NULL || RunNode->right != NULL || !IsEmpty(queue)) printf("\n");
            if(RunNode->left != NULL) enqueue(&queue,RunNode->left);
            if(RunNode->right != NULL) enqueue(&queue,RunNode->right);
        }
    }
}


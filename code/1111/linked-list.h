#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef int item;

typedef struct node{
	item data;
	struct node *next;
} node;

node *createList();

// check whether a list is empty
int isListEmpty(node *root);

// add more element
node *add(node *root, item x);

// insert new element after a specific node 
node *insertAfter(node *root, node *p, item x);

// insert new element before a specific node 
node *insertBefore(node *root, node *p, item x);

// remove an element
node *removeAt(node *root, node *p);

// search
node *find(node *root, item x);

// last node - TODO
node *last(node *root);

// nth node - TODO
node *nth(node *root, int n);

// length - TODO
int length(node *root);

// free a list
void freeList(node *root);

#endif







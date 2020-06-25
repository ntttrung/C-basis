#ifndef _BUS_LIST_
#define _BUS_LIST_

typedef struct{
    char id[10];
    int nPark;
    char park[20][10];
} busItem;

typedef struct busNode{
	busItem data;
	struct busNode *next;
} busNode;

busNode *createListBus();

// check whether a list is empty
int isListEmptyBus(busNode *root);

// add more element
busNode *addBus(busNode *root, busItem x);

// insert new element after a specific busNode 
busNode *insertAfterBus(busNode *root, busNode *p, busItem x);

// insert new element before a specific busNode 
busNode *insertBeforeBus(busNode *root, busNode *p, busItem x);

// remove an element
busNode *removeAtBus(busNode *root, busNode *p);

// search
busNode *findBus(busNode *root, char *x);

// last busNode - TODO
busNode *lastBus(busNode *root);

// nth busNode - TODO
busNode *nthBus(busNode *root, int n);

// length - TODO
int lengthBus(busNode *root);

// free a list
void freeListBus(busNode *root);

#endif
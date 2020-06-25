#ifndef _PARK_LIST_
#define _PARK_LIST_

typedef struct{
    char id[10];
    int x;
    int y;
} parkItem;

typedef struct parkNode{
	parkItem data;
	struct parkNode *next;
} parkNode;

parkNode *createListPark();

// check whether a list is empty
int isListEmptyPark(parkNode *root);

// add more element
parkNode *addPark(parkNode *root, parkItem x);

// insert new element after a specific parkNode 
parkNode *insertAfterPark(parkNode *root, parkNode *p, parkItem x);

// insert new element before a specific parkNode 
parkNode *insertBeforePark(parkNode *root, parkNode *p, parkItem x);

// remove an element
parkNode *removeAtPark(parkNode *root, parkNode *p);

// search
parkNode *findPark(parkNode *root, char *x);

// last parkNode - TODO
parkNode *lastPark(parkNode *root);

// nth parkNode - TODO
parkNode *nthPark(parkNode *root, int n);

// length - TODO
int lengthPark(parkNode *root);

// free a list
void freeListPark(parkNode *root);

#endif
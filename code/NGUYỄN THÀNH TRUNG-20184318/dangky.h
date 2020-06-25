#ifndef _DANGKY_H_
#define _DANGKY_H_
#include "monhoc.h"

typedef struct  
  {
    char id[10];
    int  soluongmh;
    monhoc_type dsmh[10];
  }
dangky_type;

struct DKNode {
  dangky_type data;
  struct DKNode *next;
};

typedef struct DKNode* dklist;
typedef struct DKNode* dknode_t;

// create new empty list
dklist dkcreate_list();

// check whether a list is empty
int dkis_empty(dklist l);

// insert new element after a specific node 
dklist dkinsert_after(dklist l, dknode_t p, dangky_type x);

dklist dkinsert_tail(dklist l,dangky_type x);

// insert new element before a specific node 
dklist dkinsert_before(dklist l, dknode_t p, dangky_type x);

// remove an element
dklist dkremove_at(dklist l, dknode_t p);

// search
dknode_t dkfind(dklist l, char* x);

// first node - TODO
dknode_t dkfirst(dklist l);

// last node - TODO
dknode_t dklast(dklist l);

// nth node - TODO
dknode_t dknth(dklist l, int n);

// length - TODO
int dklength(dklist l);

// nth node - TODO
dklist dkreverse(dklist l);


// free a list
void dkfree_list(dklist l);


#endif

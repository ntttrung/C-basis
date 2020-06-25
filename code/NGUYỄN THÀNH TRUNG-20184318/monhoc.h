#ifndef _MONHOC_H_
#define _MONHOC_H_

typedef struct 
  {
    char id[10];
    int so_tin_chi;
    int hoc_ky;
  }
monhoc_type;

struct MHNode {
  monhoc_type data;
  struct MHNode *next;
};

typedef struct MHNode* mhlist;
typedef struct MHNode* mhnode_t;

// create new empty list
mhlist mhcreate_list();

// check whether a list is empty
int mhis_empty(mhlist l);

// insert new element after a specific node 
mhlist mhinsert_after(mhlist l, mhnode_t p, monhoc_type x);

mhlist mhinsert_tail(mhlist l, monhoc_type x);

// insert new element before a specific node 
mhlist mhinsert_before(mhlist l, mhnode_t p, monhoc_type x);

// remove an element
mhlist mhremove_at(mhlist l, mhnode_t p);

// search
mhnode_t mhfind(mhlist l, char* x);

// first node - TODO
mhnode_t mhfirst(mhlist l);

// last node - TODO
mhnode_t mhlast(mhlist l);

// nth node - TODO
mhnode_t mhnth(mhlist l, int n);

// length - TODO
int mhlength(mhlist l);

// nth node - TODO
mhlist mhreverse(mhlist l);


// free a list
void mhfree_list(mhlist l);


#endif

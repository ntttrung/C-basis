#ifndef _TUYENXE_H_
#define _TUYENXE_H_
#include<string.h>

#include "diemdo.h"

typedef struct
  {
    char id[10];
    int sodiemdo;
    bus_type dsDiemdo[10];
  }
tx_type;

struct TxNode {
  tx_type data;
  struct TxNode *next;
};

typedef struct TxNode* txlist;
typedef struct TxNode* txnode_t;

// create new empty list
txlist txcreate_list();

// check whether a list is empty
int txis_empty(txlist l);

txlist txinsert_tail(txlist l,tx_type x);

// insert new element after a specific node 
txlist txinsert_after(txlist l, txnode_t p, tx_type x);

// insert new element before a specific node 
txlist txinsert_before(txlist l, txnode_t p, tx_type x);

// remove an element
txlist txremove_at(txlist l, txnode_t p);

// search
txnode_t txfind(txlist l, char* x);

// first node - TODO
txnode_t txfirst(txlist l);

// last node - TODO
txnode_t txlast(txlist l);

// nth node - TODO
txnode_t txnth(txlist l, int n);

// length - TODO
int txlength(txlist l);

// nth node - TODO
txlist txreverse(txlist l);


// free a list
void txfree_list(txlist l);


#endif

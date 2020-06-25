#ifndef _DIEMDO_H_
#define _DIEMDO_H_

typedef struct
  {
    char id[10];
    int x;
    int y;
  }
bus_type;

struct BusNode {
  bus_type data;
  struct BusNode *next;
};

typedef struct BusNode* buslist;
typedef struct BusNode* busnode_t;

// create new empty list
buslist buscreate_list();

// check whether a list is empty
int busis_empty(buslist l);

buslist businsert_tail(buslist l, bus_type x);

// insert new element after a specific node 
buslist businsert_after(buslist l, busnode_t p, bus_type x);

// insert new element before a specific node 
buslist businsert_before(buslist l, busnode_t p, bus_type x);

// remove an element
buslist busremove_at(buslist l, busnode_t p);

// search
busnode_t busfind(buslist l,char* x);

// first node - TODO
busnode_t busfirst(buslist l);

// last node - TODO
busnode_t buslast(buslist l);

// nth node - TODO
busnode_t busnth(buslist l, int n);

// length - TODO
int buslength(buslist l);

// nth node - TODO
buslist busreverse(buslist l);


// free a list
void busfree_list(buslist l);


#endif

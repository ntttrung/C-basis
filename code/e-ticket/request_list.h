#ifndef _REQUEST_LIST_H_
#define _REQUEST_LIST_H_
#include "request.h"
typedef struct Request rl_element_t;

struct Node {
  rl_element_t data;
  struct Node *next;
};

typedef struct Node* rl_list;
typedef struct Node* rl_node_t;

// create new empty list
rl_list rl_create();

// check whether a list is empty
int rl_is_empty(rl_list l);

// insert new element after a specific node 
rl_list rl_insert_after(rl_list l, rl_node_t p, rl_element_t x);

// insert new element before a specific node 
rl_list rl_insert_before(rl_list l, rl_node_t p, rl_element_t x);

// remove an element
rl_list rl_remove_at(rl_list l, rl_node_t p);

// search
rl_node_t rl_find(rl_list l, char *name);

// first node - TODO
rl_node_t rl_first(rl_list l);

// last node - TODO
rl_node_t rl_last(rl_list l);

// nth node - TODO
rl_node_t nth(rl_list l, int n);

// length - TODO
int rl_length(rl_list l);



// free a list
void rl_free(rl_list l);


#endif

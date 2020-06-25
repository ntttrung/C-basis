#ifndef _LIST_H_
#define _LIST_H_

#include "tree.h"

typedef struct person
  {
    char name[20];
    element_t food[20];
    int count_food;
    int times;
  }person_t;

struct Node {
  person_t data;
  struct Node *next;
};

typedef struct Node* list;
typedef struct Node* node_t;

// create new empty list
list create_list();

// check whether a list is empty
int is_empty(list l);

// insert new element after a specific node 
list insert_after(list l, node_t p, person_t x);

list insert_tail(list l,person_t x);

// insert new element before a specific node 
list insert_before(list l, node_t p, person_t x);

// remove an element
list remove_at(list l, node_t p);

// search
node_t find(list l, char* x);

// first node - TODO
node_t first(list l);

// last node - TODO
node_t last(list l);

// nth node - TODO
node_t nth(list l, int n);

// length - TODO
int length(list l);

// nth node - TODO
// list reverse(list l);




// free a list
void free_list(list l);

int find_food(node_t l,char *x);

#endif

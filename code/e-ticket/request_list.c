#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "request_list.h"

rl_node_t rl_make_node(rl_element_t x) {
  rl_node_t n = (rl_node_t)malloc(sizeof(struct Node));
  n->data = x;
  n->next = NULL;
  return n;
}

// create new empty list
rl_list rl_create() {
  return NULL;
}

// check whether a list is empty
int rl_is_empty(rl_list l) {
  return (l == NULL);
}


// insert new element after a specific node 
rl_list rl_insert_after(rl_list l, rl_node_t p, rl_element_t x) {
  rl_node_t n = rl_make_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}

// insert new element before a specific node 
rl_list rl_insert_before(rl_list l, rl_node_t p, rl_element_t x) {
  rl_node_t n = rl_make_node(x);
  rl_node_t prev;
  
  if (l == NULL) {
    return n;
  } else if (l == p) {
    n->next = l;
    return n;
  } else {
    for (prev = l; prev->next != p; prev = prev->next);
    n->next = p;
    prev->next = n;
    return l;
  }
}

// remove an element
rl_list rl_remove_at(rl_list l, rl_node_t p) {
  rl_node_t prev;
  
  if (l == NULL)
    return NULL;
  else if (l == p) {
    l = p->next;
    free(p);
    return l;
  } else {
    for (prev = l; prev->next != p; prev = prev->next);
    prev->next = p->next;
    free(p);
    return l;
  }
}

// search
rl_node_t rl_find(rl_list l, char *name) {
  rl_node_t p = l;

  while ((p != NULL) && (strcmp((p->data).name, name) == 0))
    p = p->next;

  return p;
}

// free a list
void rl_free(rl_list l) {
  rl_node_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

// nth node - TODO
rl_node_t nth(rl_list l, int n) {
  rl_node_t p = l;
  int count = 1;
  while ((p != NULL) && (count < n)) {
    p = p->next;
    count ++;
  }
  return p;
}

// first node - TODO
rl_node_t rl_first(rl_list l) {
  return l;
}

// last node - TODO
rl_node_t rl_last(rl_list l) {
  rl_node_t p = l;
  if (p == NULL) return NULL;
  while (p->next != NULL)
    p = p->next;
  return p;
}

// last node - TODO
int rl_length(rl_list l) {
  rl_node_t p = l;
  int count = 0;
  while (p != NULL) {
    p = p->next;
    count ++;
  }
  return count;
}

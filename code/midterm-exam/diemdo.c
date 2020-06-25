#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "diemdo.h"

busnode_t busmake_node(bus_type x) {
  busnode_t n = (busnode_t)malloc(sizeof(struct BusNode));
  n->data = x;
  n->next = NULL;
  return n;
}

// create new empty list
buslist buscreate_list() {
  return NULL;
}

// check whether a list is empty
int busis_empty(buslist l) {
  return (l == NULL);
}


// insert new element after a specific node 
buslist businsert_after(buslist l, struct BusNode *p, bus_type x) {
  busnode_t n = busmake_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}
buslist businsert_tail(buslist l, bus_type x)
  {
    busnode_t p=l;
    busnode_t n=busmake_node(x);
    if(l==NULL)
      {
        return n;
      }
    else
      {
        while(p->next!=NULL)
          {
            p=p->next;
          }
        p->next=n;
        return l;
      }
  }

// insert new element before a specific node 
buslist businsert_before(buslist l, struct BusNode *p, bus_type x) {
  busnode_t n = busmake_node(x);
  busnode_t prev;
  
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
buslist busremove_at(buslist l, struct BusNode *p) {
  busnode_t prev;
  
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
busnode_t busfind(buslist l, char* x) {
  busnode_t p = l;

  while ((p != NULL) && (strcasecmp(p->data.id,x)!=0))
    p = p->next;
  return p;
}

// free a list
void busfree_list(buslist l) {
  busnode_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

// first node - TODO
busnode_t busfirst(buslist l)
  {
    return l;
  }

// last node - TODO
busnode_t buslast(buslist l)
  {
    busnode_t p=l;
    if(l==NULL)
      printf("List is empty\n");
    else while(p->next!=NULL)
      {
        p=p->next;
      }
    return p;
  }

// length - TODO
int buslength(buslist l)
  {
    int i=1;
    busnode_t p=l;
    if(l==NULL)
      return 0;
    else while(p->next!=NULL)
      {
        p=p->next;
        i++;
      }
    return i;
  }

// nth node - TODO
busnode_t busnth(buslist l, int n)
  {
    int i=buslength(l);
    int j=1;
    busnode_t p=l;
    if(n>i)
      printf("Cannot find\n");
    else while(p->next!=NULL)
            {
              if(n==j)
                return p;
              else 
                {
                  j++;
                  p=p->next;
                }
            }
  }



























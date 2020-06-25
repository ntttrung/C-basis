#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "dangky.h"

dknode_t dkmake_node(dangky_type x) {
  dknode_t n = (dknode_t)malloc(sizeof(struct DKNode));
  n->data = x;
  n->next = NULL;
  return n;
}

// create new empty list
dklist dkcreate_list() {
  return NULL;
}

// check whether a list is empty
int dkis_empty(dklist l) {
  return (l == NULL);
}


// insert new element after a specific node 
dklist dkinsert_after(dklist l, struct DKNode *p, dangky_type x) {
  dknode_t n = dkmake_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}

// insert new element before a specific node 
dklist dkinsert_before(dklist l, struct DKNode *p, dangky_type x) {
  dknode_t n = dkmake_node(x);
  dknode_t prev;
  
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
dklist dkremove_at(dklist l, struct DKNode *p) {
  dknode_t prev;
  
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
dknode_t dkfind(dklist l, char* x) {
  dknode_t p = l;

  while ((p != NULL) && (strcasecmp(p->data.id,x)!=0))
    p = p->next;

  return p;
}

// free a list
void dkfree_list(dklist l) {
  dknode_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

// first node - TODO
dknode_t dkfirst(dklist l)
  {
    return l;
  }

// last node - TODO
dknode_t dklast(dklist l)
  {
    dknode_t p=l;
    if(l==NULL)
      printf("List is empty\n");
    else while(p->next!=NULL)
      {
        p=p->next;
      }
    return p;
  }

// length - TODO
int dklength(dklist l)
  {
    int i=1;
    dknode_t p=l;
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
dknode_t dknth(dklist l, int n)
  {
    int i=dklength(l);
    int j=1;
    dknode_t p=l;
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

dklist dkinsert_tail(dklist l,dangky_type x)
  {
    dknode_t p=l;
    dknode_t n=dkmake_node(x);
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


























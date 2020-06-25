#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "monhoc.h"

mhnode_t mhmake_node(monhoc_type x) {
  mhnode_t n = (mhnode_t)malloc(sizeof(struct MHNode));
  n->data = x;
  n->next = NULL;
  return n;
}

// create new empty list
mhlist mhcreate_list() {
  return NULL;
}

// check whether a list is empty
int mhis_empty(mhlist l) {
  return (l == NULL);
}


// insert new element after a specific node 
mhlist mhinsert_after(mhlist l, struct MHNode *p, monhoc_type x) {
  mhnode_t n = mhmake_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}

// insert new element before a specific node 
mhlist mhinsert_before(mhlist l, struct MHNode *p, monhoc_type x) {
  mhnode_t n = mhmake_node(x);
  mhnode_t prev;
  
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
mhlist mhremove_at(mhlist l, struct MHNode *p) {
  mhnode_t prev;
  
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
mhnode_t mhfind(mhlist l, char* x) {
  mhnode_t p = l;

  while ((p != NULL) && (strcasecmp(p->data.id,x)!=0))
    p = p->next;

  return p;
}

// free a list
void mhfree_list(mhlist l) {
  mhnode_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

// first node - TODO
mhnode_t mhfirst(mhlist l)
  {
    return l;
  }

// last node - TODO
mhnode_t mhlast(mhlist l)
  {
    mhnode_t p=l;
    if(l==NULL)
      printf("List is empty\n");
    else while(p->next!=NULL)
      {
        p=p->next;
      }
    return p;
  }

// length - TODO
int mhlength(mhlist l)
  {
    int i=1;
    mhnode_t p=l;
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
mhnode_t mhnth(mhlist l, int n)
  {
    int i=mhlength(l);
    int j=1;
    mhnode_t p=l;
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

mhlist mhinsert_tail(mhlist l,monhoc_type x)
  {
    mhnode_t p=l;
    mhnode_t n=mhmake_node(x);
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


























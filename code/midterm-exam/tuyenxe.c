#include <stdlib.h>
#include <stdio.h>

#include "tuyenxe.h"

txnode_t txmake_node(tx_type x) {
  txnode_t n = (txnode_t)malloc(sizeof(struct TxNode));
  n->data = x;
  n->next = NULL;
  return n;
}

// create new empty list
txlist txcreate_list() {
  return NULL;
}

// check whether a list is empty
int txis_empty(txlist l) {
  return (l == NULL);
}
txlist txinsert_tail(txlist l,tx_type x)
  {
    txnode_t p=l;
    txnode_t n=txmake_node(x);
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

// insert new element after a specific node 
txlist txinsert_after(txlist l, struct TxNode *p, tx_type x) {
  txnode_t n = txmake_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}

// insert new element before a specific node 
txlist txinsert_before(txlist l, struct TxNode *p, tx_type x) {
  txnode_t n = txmake_node(x);
  txnode_t prev;
  
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
txlist txremove_at(txlist l, struct TxNode *p) {
  txnode_t prev;
  
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
txnode_t txfind(txlist l, char *x) {
  txnode_t p = l;

  while ((p != NULL) && (strcasecmp(p->data.id,x)!=0))
    p = p->next;

  return p;
}

// free a list
void txfree_list(txlist l) {
  txnode_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

// first node - TODO
txnode_t txfirst(txlist l)
  {
    return l;
  }

// last node - TODO
txnode_t txlast(txlist l)
  {
    txnode_t p=l;
    if(l==NULL)
      printf("List is empty\n");
    else while(p->next!=NULL)
      {
        p=p->next;
      }
    return p;
  }

// length - TODO
int txlength(txlist l)
  {
    int i=1;
    txnode_t p=l;
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
txnode_t txnth(txlist l, int n)
  {
    int i=txlength(l);
    int j=1;
    txnode_t p=l;
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



























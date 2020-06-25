#include <stdlib.h>
#include<stdio.h>
#include "dllist.h"

//make_node
node_t make_node(element_t x)
  {
    node_t n=(node_t)malloc(sizeof(node_t));
    n->data=x;
    n->next=NULL;
    n->prev=NULL;
    return n;
  }

// create new empty list
dllist create_list() {
    return NULL;
}

// check whether a list is empty
int is_empty(dllist l) {
  return(l==NULL);
}


// insert new element after a specific node 
dllist insert_after(dllist l, node_t p, element_t x) {
      node_t n=make_node(x);
      if(l==NULL)
        return n;
      else
          {
            n->next=p->next;
            p->next=n;
            n->prev=p;
          }
      return l;
      
}


// insert new element before a specific node 
dllist insert_before(dllist l, node_t p, element_t x) {
  node_t n=make_node(x);
  if(l==NULL)
    return n;
  else 
      {
        p=p->prev;
        insert_after(l,p,x);
      }
}


// remove an element
dllist remove_at(dllist l, node_t p) {
    node_t cur;
    if(l==NULL)
        return NULL;
    else if(l==p)
        {
          l=p->next;
          l->prev=NULL;
          free(p);
          return l;
        }
      else
        {
          p->prev->next=p->next->prev;
          free(p);
          return l;
        }
}


// search
node_t find(dllist l, element_t x) {
      node_t p=l;
      while((p->next!=NULL) && (p->data!=x))
        {
           p=p->next;
        }
      return p;
}


// first node
node_t first(dllist l) {
  return l;
}


// last node
node_t last(dllist l) {
  node_t p=l;
    if(l==NULL)
      printf("List is empty\n");
    else while(p->next!=NULL)
      {
        p=p->next;
      }
    return p;
}


// nth node
node_t nth(dllist l, int n) {
  int i=length(l);
    int j=1;
    node_t p=l;
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


// length
int length(dllist l) {
  int i=1;
    node_t p=l;
    if(l==NULL)
      return 0;
    else while(p->next!=NULL)
      {
        p=p->next;
        i++;
      }
    return i;
}

// free a list
void free_list(dllist l) {
  node_t p = l;
  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

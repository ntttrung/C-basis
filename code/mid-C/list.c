#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "list.h"

node_t make_node(person_t x) {
  node_t n = (node_t)malloc(sizeof(struct Node));
  n->data = x;
  n->next = NULL;
  return n;
}

// create new empty list
list create_list() {
  return NULL;
}

// check whether a list is empty
int is_empty(list l) {
  return (l == NULL);
}


// insert new element after a specific node 
list insert_after(list l, struct Node *p, person_t x) {
  node_t n = make_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}

// insert new element before a specific node 
list insert_before(list l, struct Node *p, person_t x) {
  node_t n = make_node(x);
  node_t prev;
  
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
list remove_at(list l, struct Node *p) {
  node_t prev;
  
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
node_t find(list l, char* x) {
  node_t p = l;

  while ((p != NULL) && (strcasecmp(p->data.name,x)!=0))
    p = p->next;

  return p;
}

// free a list
void free_list(list l) {
  node_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

// first node - TODO
node_t first(list l)
  {
    return l;
  }

// last node - TODO
node_t last(list l)
  {
    node_t p=l;
    if(l==NULL)
      printf("List is empty\n");
    else while(p->next!=NULL)
      {
        p=p->next;
      }
    return p;
  }

// length - TODO
int length(list l)
  {
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

// nth node - TODO
node_t nth(list l, int n)
  {
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

list insert_tail(list l,person_t x)
  {
    node_t p=l;
    node_t n=make_node(x);
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

int find_food(node_t l,char *x)
  {
    int i;
    for(i=1;i<=l->data.count_food;i++)
      if(strcasecmp(l->data.food[i].name,x)==0) return i;
    return 0;
  }




























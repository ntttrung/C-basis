#include <stdio.h>
#include <stdlib.h>
#include "stack-list.h"
struct Node makenode(element_t x)
{
	struct Node new;
	new = (struct Node )malloc(sizeof(struct Node));
	new->data = x ;
	new->next = NULL;
	return new;
}

stack create_stack() {
  // TODO
	return NULL;
}

int is_empty(stack s) {
  // TODO
	return (s == NULL);
}

int is_full(stack s) 
{
	int count = 1
	stack p=s;
	while(p->next != NULL)
	{
		count++;
	}
	if(count == MAX_LEN)
		return 1;
	else
		return 0;

  // TODO
}

element_t top(stack s) 
{
	return s->data;
  // TODO
}

stack push(stack s, element_t x) 
{
	struct Node new = makenode(x);
	new->next = s;
	s = new;
	return s;
  // TODO
}

stack pop(stack s) 
{
	struct Node p;
	p = s;
	
	s = s->next;
	free(p);
	return s;

  // TODO
}

void free_stack(stack s) 
{
	struct Node p;
	p = s;
	while(s->next != NULL)
	{
		s = s->next;
		free(p);
		p=s;
	}
  // TODO
}

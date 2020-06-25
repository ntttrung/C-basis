#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "stack-arr-struct.h"

stack create_stack() 
{
  stack s = (stack)malloc(sizeof(struct Stack));
  s->top = 0;
}

int is_empty(stack s) {
  return (s->top == 0);
}

int is_full(stack s) {
  return (s->top == (MAX_LEN));
}

address top(stack s) {
  if (s->top != 0)
    return s->data[s->top];
  else {
    printf("Stack underflow!\n");
    exit(0);
  }
}

stack push(stack s, address x) {
  if (s->top >= MAX_LEN) {
    printf("Stack overflow\n");
    exit(0);
  } else {
            s->top++;
            strcpy((s->data[s->top]).name,x.name);
            strcpy((s->data[s->top]).phone,x.phone);
            strcpy((s->data[s->top]).email,x.email);
  }
  return s;
}

stack pop(stack s) {
  if (s->top == 0) {
    printf("Stack underflow!\n");
    exit(0);
  } else {
    s->top--;
  }
  return s;
}

void free_stack(stack s) {
  free(s);}

stack reserse(stack s)
  {
    stack p;
    p=create_stack();
    while(s->top!=0)
      {
        p=push(p,top(s));
        s=pop(s);
      }
    return p;
  }

void xoa(char s[90],int vitrixoa)
{
    int i,n;
	n=strlen(s);
    for(i=vitrixoa;i<n;i++)
         s[i]=s[i+1];
	s[n-1]='\0';
}
void xoakt(char*s)
{
       int i;

    for(i=0;i<strlen(s);i++)
		if(s[i]==' '&& s[i+1]==' ')
		{
			xoa(s,i);
			i--;
		}
    if(s[0]==' ')
		xoa(s,0);
    if(s[strlen(s)-1]==' ')
		xoa(s,strlen(s)-1);
}

















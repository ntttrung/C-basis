#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "stack-array.h"

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

element_t top(stack s) {
  if (s->top != 0)
    return s->data[s->top];
  else {
    printf("Stack underflow!\n");
    exit(0);
  }
}

stack push(stack s, element_t x) {
  if (s->top >= MAX_LEN) {
    printf("Stack overflow\n");
    exit(0);
  } else {
    s->top++;
    s->data[s->top] = x;
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

element_t resul(int num1,int num2, char c)
    {
        switch(c)
            {
                case '+': return num1+num2;
                case '-': return num1-num2;
                case '*': return num1*num2;
            }
    }

element_t polish_notation(char *str)
    {
        int num1,num2,i;
        stack s=create_stack();
        for(i=0;i<strlen(str);i++)
            if(isdigit(str[i])!=0)
                s=push(s,str[i]-'0');
            else 
                {
                    if(s->top<2)
                      {
                        printf("ERROR\n");
                        exit(0);
                      }
                    else
                        {
                          num2=top(s);
                          s=pop(s);
                          num1=top(s);
                          s=pop(s);
                          s=push(s,(resul(num1,num2,str[i])));
                        }
                    
                }
        if(s->top!=1)
          {
            printf("ERROR\n");
            exit(0);
          }
        else return top(s);
    }
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
















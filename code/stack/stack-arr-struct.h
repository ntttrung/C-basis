#ifndef _STACK_ARR_STRUCT_H_
#define _STACK_ARR_STRUCT_H_

#define MAX_LEN  100


typedef struct
    {
        char name[50];
        char phone[30];
        char email[50];
    }
address;

struct Stack {
  address data[MAX_LEN];
  int top;
};

typedef struct Stack* stack;

// create new empty stack
stack create_stack();

int is_empty(stack s);

int is_full(stack s);

address top(stack s);

stack push(stack s, address x);

stack pop(stack s);

void free_stack(stack s);

stack reserse(stack s);
void xoa(char s[90],int vitrixoa);
void xoakt(char*s);

#endif

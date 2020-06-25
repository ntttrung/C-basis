#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack-array.h"

// Ket qua tra ve duoc luu o tham bien result
// Gia tri tra ve = 0 : tinh toan thanh cong
// Gia tri tra ve = 1 : sai cu phap bieu thuc
int evaluate(char *exp, int *result);

int main(int argc, char* argv[]) {
  int result, err;
  
  if (argc != 2) {
    printf("Syntax error|\nUsage: evaluate [exp]\n");
    exit(0);
  }

  err = evaluate(argv[1], &result);

  if (err != 0) {
    printf("Invalid expression!\n"); 
  } else {
    printf("Result: %d\n", result);
  }
  return 0;
}

int evaluate(char *exp, int *result) {
  char *c = exp;
  stack s = create_stack();
  int arg1, arg2, r;
  
  while (*c != 0) {
    if (isdigit(*c)) {
      s = push(s, *c - '0');
    } else {
      if (is_empty(s)) {
	free_stack(s);
	return 1;
      }
      arg2 = top(s); s = pop(s);
      if (is_empty(s)) {
	free_stack(s);
	return 1;
      }
      arg1 = top(s); s = pop(s);

      switch (*c) {
      case '+':
	r = arg1 + arg2;
	break;
      case '-':
	r = arg1 - arg2;
	break;
      case '*':
	r = arg1 * arg2;
	break;
      case '/':
	r = arg1 / arg2;
	break;
      default:
	free_stack(s);
	return 1;
      }
      s = push(s, r);
    }
    c ++;
  }
  if (is_empty(s)) {
    free_stack(s);
    return 1;
  } else {
    *result = top(s); s = pop(s);
    if (is_empty(s)) {
      free_stack(s);
      return 0;
    } else {
      free_stack(s);
      return 1;
    }
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exp.h"

exp createNullExp() {
  return (exp)NULL;
}

exp createExp(element_t x, exp l, exp r) {
  exp e = (exp)malloc(sizeof(struct ExpNode));
  e->data = x;
  e->left = l;
  e->right = r;
  return e;
}
exp createArg(element_t x) {
  return createExp(x, createNullExp(), createNullExp());
}

int isNullExp(exp e) {
  return (e == NULL);
}
int isArg(exp e) {
  return ((e != NULL) &&
	  (e->left == NULL) &&
	  (e->right == NULL)); 
}

exp left(exp e) {
  if (isNullExp(e))
    return NULL;
  else return e->left;
}

exp right(exp e) {
  if (isNullExp(e))
    return NULL;
  else return e->right;
}
element_t value(exp e) {
  if (isNullExp(e))
    return 0;
  else return e->data;
}

char* expToString(exp e) {
  char *result;
  char *l;
  char *r;
  
  if (isNullExp(e)) {
    // Bieu thuc rong
    result = (char*)malloc(1);
    strcpy(result, "");
    return result;
  } else if (isArg(e)) {
    // Toan hang
    result = (char*)malloc(4);
    sprintf(result, "%c", value(e));
    return result;
  } else if (right(e) == NULL) {
    // Toan tu mot ngoi
    l = expToString(left(e));
    result = (char*)malloc(4 + strlen(l));
    sprintf(result, "%c%s", value(e), l);
  } else {
    // Toan tu hai ngoi
    l = expToString(left(e));
    r = expToString(right(e));
    
    result = (char*)malloc(4 + strlen(l) + strlen(r));
    sprintf(result, "%s %c %s", l, value(e), r);
    free(l);
    free(r);
    return result;
  }
}
element_t evaluate(exp e) {
  element_t arg1, arg2, result;
  
  if (isNullExp(e))
    return 0;
  else if (isArg(e)) {
    return (value(e) - '0');
  } else if (right(e) == NULL) {
    if (value(e) == '!')
      return -(value(e) - '0');
    else {
      printf("Wrong expession!\n");
      exit(0);
    }
  } else {
    arg1 = evaluate(left(e));
    arg2 = evaluate(right(e));
    switch (value(e)) {
    case '+':
      result = arg1 + arg2;
      break;
    case '-':
      result = arg1 - arg2;
      break;
    case '*':
      result = arg1 * arg2;
      break;
    case '/':
      result = arg1 / arg2;
      break;
    default:
      printf("Wrong expession!\n");
      exit(0);
    }
    return result;
  }
}

exp stringToExp(char* s) {
  // TODO
  return NULL;
}

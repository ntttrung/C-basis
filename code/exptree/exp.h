#ifndef _EXP_H_
#define _EXP_H_

typedef char element_t;

struct ExpNode {
  element_t data;
  struct ExpNode *left;
  struct ExpNode *right;
};

typedef struct ExpNode* exp;

exp createNullExp();
exp createArg(element_t x);
exp createExp(element_t x, exp l, exp r);

int isNullExp(exp e);
int isArg(exp e);

exp left(exp e);
exp right(exp e);
element_t value(exp e);

char* expToString(exp e);
element_t evaluate(exp e);

exp stringToExp(char* s);
#endif

#include <stdio.h>
#include "stack-array.h"

int main() {

  stack s = create_stack();

  s = push(s, 1);
  s = push(s, 2);
  s = push(s, 3);

  while (!is_empty(s)) {
    printf("%d\n", top(s));
    s = pop(s);
  }
  
  
  return 0;
}

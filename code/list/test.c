#include <stdio.h>
#include "list.h"

int main() {

  list l = create_list();
  node_t p;

  l = insert_before(l,l,7);
  l = insert_before(l,l,20);
  l = insert_before(l,l,3);
  l = insert_before(l,l,3);
  l = insert_before(l,l,3);
  l = insert_before(l,l,3);
  l = insert_before(l,l,3);
  l = insert_before(l,l,3);
  l = insert_before(l,l,3);
  
  return 0;
}

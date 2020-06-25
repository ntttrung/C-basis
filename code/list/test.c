#include <stdio.h>
#include "list.h"

int main() {

  list l = create_list();
  node_t p;

  l = insert_before(l,l,1);
  l = insert_before(l,l,2);
  l = insert_before(l,l,3);
  

  node_t del;
  del = find(l,1);
  l = remove_at(l, del);

  
  printf("%d\n",length(l));
  return 0;
}

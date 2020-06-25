#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main() {
  tree t=createNullTree();
  int i;
  int a[] = {3,6,2,7,1,4,10};
  for(i=0;i<=6;i++)
    t=insertBST(t,a[i]);
 breadth_first_search(t);
}


#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
  int a[] = {3,6,2,7,4,10};
  int i, n = 6;
  tree t = createNullTree();

  for (i = 0; i < n; i++)
    t = insertBST(t, a[i]);

  printf("%d\n",innerNodeCount(t));

  char *s;
  s = treeToString(t);
  printf("%s\n", s);
  free(s);

  t = removeBST(t, 4);
  s = treeToString(t);
  printf("%s\n", s);
  free(s);

  t = removeBST(t, 6);
  s = treeToString(t);
  printf("%s\n", s);
  free(s);

  t = removeBST(t, 3);
  s = treeToString(t);
  printf("%s\n", s);
  free(s);

  return 0;
}


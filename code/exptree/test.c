#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
  tree t = createTree(1,
		      createLeaf(2),
		      createTree(3,
				 createLeaf(4),
				 createLeaf(5)));
  char *s;
  printf("size = %d\n", sizeOfTree(t));
  printf("sum = %d\n", sumOfTree(t));
  s = treeToString(t);
  printf("%s\n", s);
  free(s);
  
  printf("left most:%d\n", value(leftMost(t)));
  printf("right most:%d\n", value(rightMost(t)));

  t = addToLeftMost(t, 6);
  t = addToRightMost(t, 7);

  s = treeToString(t);
  printf("%s\n", s);
  free(s);

  printf("Height:%d\n", height(t));
  printf("Leaves count:%d\n", leavesCount(t));
  printf("Inner node count:%d\n", innerNodeCount(t));
  printf("Right children count:%d\n", rightChildCount(t));
  return 0;
}

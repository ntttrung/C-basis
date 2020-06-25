#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#i

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

void printLevelOrder(tree t) {
	if(t == NULL) return;
	queue<Node*> bf_queue;
	bf_queue.push(root);  
	/* Vòng lặp kết thúc khi queue rỗng */
	while(!bf_queue.empty()) {
		Node* current = bf_queue.front();
		bf_queue.pop(); /* Lấy phần tử đầu tiên ra khỏi queue */
		cout<<current->data<<", ";
                  /* Enqueue con trái và con phải của current vào bf_queue.*/
		if(current->left != NULL) {
                      bf_queue.push(current->left);
                  }
		if(current->right != NULL) {
                      bf_queue.push(current->right);
                   }
	}
}


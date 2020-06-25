#include <stdio.h>
#include "queue.h"

int main() {
  queue q = create_queue();

  q = enqueue(q, 1);
  q = enqueue(q, 2);
  q = enqueue(q, 3);

  while (!is_empty(q)) {
    printf("%d\n", front(q));
    q = dequeue(q);
  }

  free_queue(q);
  return 0;
}

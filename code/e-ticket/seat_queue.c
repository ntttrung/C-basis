#include <stdio.h>
#include <stdlib.h>
#include "seat_queue.h"

sq_queue sq_create() {
  sq_queue q = (sq_queue) malloc(sizeof(struct SeatQueue));
  q->f = q->r = -1;
  return q;
}

int sq_is_empty(sq_queue q) {
  return (q->f == -1);
}

int sq_is_full(sq_queue q) {
  return ((q->f == 0) && (q->r == (MAX_LEN - 1)) ||
	  (q->f == (q->r + 1)));
}

sq_queue sq_enqueue(sq_queue q, sq_element_t x) {
  if (q->f == -1) {
    q->data[0] = x;
    q->f = q->r = 0;
  } else if (sq_is_full(q)) {
    printf("Overflow!\n");
  } else {
    q->r++;
    if (q->r >= MAX_LEN) q->r = 0;
    q->data[q->r] = x;
  }
  return q;
}

sq_queue sq_delete(sq_queue q, sq_element_t x)
  {
    int c;
    sq_queue tmp=sq_create();
    for(c=q->f;c<=q->r;c++)
      {
        if((q->data[c].row!=x.row)||(q->data[c].col!=x.col))
            tmp=sq_enqueue(tmp,q->data[c]);
      }
    return tmp;
  }

sq_queue sq_dequeue(sq_queue q) {
  if (q->f == -1) {
    printf("Underflow!\n");
  } else if (q->f == q->r) {
    q->f = q->r = -1;
  } else {
    q->f++;
    if (q->f >= MAX_LEN) q->f = 0;
  }
  return q;
}

sq_element_t sq_front(sq_queue q) {
  if (q->f == -1) {
    printf("Underflow!\n");
    exit(0);
  } else {
    return q->data[q->f];
  }
}

sq_element_t sq_rear(sq_queue q) {
  if (q->f == -1) {
    printf("Underflow!\n");
    exit(0);
  } else {
    return q->data[q->r];
  }
}

void sq_free(sq_queue q) {
  free(q);
}

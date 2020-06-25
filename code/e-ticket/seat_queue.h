#ifndef __SEAT_QUEUE__H__
#define __SEAT_QUEUE__H__
#include"request.h"
#define MAX_LEN 100

typedef struct Seat sq_element_t;
struct SeatQueue {
  sq_element_t data[MAX_LEN];
  int f, r;
};

typedef struct SeatQueue* sq_queue;
  
sq_queue sq_create();
int sq_is_empty(sq_queue q);
int sq_is_full(sq_queue q);

sq_queue sq_enqueue(sq_queue q, sq_element_t x);
sq_queue sq_dequeue(sq_queue q);
sq_element_t sq_front(sq_queue q);
sq_element_t sq_rear(sq_queue q);

sq_queue sq_delete(sq_queue q, sq_element_t x);
void sq_free(sq_queue q);

#endif

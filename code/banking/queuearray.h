#ifndef _QUEUE_ARRAY_H_
#define _QUEUE_ARRAY_H_

#define  MAX_LEN 1000

typedef struct
    {
        int hour;
        int min;
        int wai[10];
        int actual_wait;
    }
element_t;

struct Queue
{
    element_t data[MAX_LEN];
    int front, rear;
};

typedef struct Queue* queue;

queue create_queue();

int is_empty(queue q);

int is_full(queue q);

queue enqueue(queue q, element_t x);



queue dequeue(queue q);

element_t front(queue q);

element_t rear(queue q);

void free_queue(queue q);

#endif
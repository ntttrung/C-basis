#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef int element_t;
struct Node
{
    element_t data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

typedef struct Queue *queue;
typedef struct Node* node;

queue creat_queue();

int is_empty(queue q);

int is_full(queue q);

queue enqueue(queue q, element_t x);

queue dequeue(queue q);

element_t front(queue q);

element_t rear(queue q);

void printqueue(queue q);

int length(queue q);

void free_queue(queue q);


#endif
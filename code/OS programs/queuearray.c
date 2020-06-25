#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queuearray.h"

queue create_queue(){
    queue q = (queue) malloc (sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int is_empty(queue q){
    return (q->front == -1);
}

int is_full(queue q){
    return (((q->front == 0) && (q->rear == MAX_LEN - 1)) || (q->front == q->rear + 1));
}

queue enqueue (queue q, element_t x){
    if (is_full(q)){
        printf("ERROR. Queue is full.\n");
        exit(1);
    }
    else if (is_empty(q))
    {
        q->front = 0;
        q->rear += 1;
        q->data[q->rear] = x;
        return q;
    }else
    {
        q->rear = ((q->rear) + 1) % MAX_LEN;
        q->data[q->rear] = x;
        return q;
    }
}
queue delete(queue q, element_t x)
  {
    int c;
    queue tmp=create_queue();
    for(c=q->front;c<=q->rear;c++)
      {
        if(strcasecmp(q->data[c].id,x.id)!=0)
            tmp=enqueue(tmp,q->data[c]);
      }
    return tmp;
  }

queue dequeue(queue q){
   if(q->front ==-1)
    {
        printf("Underflow!\n");
    }
    else if(q->front==q->rear)
            {
                q->front=q->rear=-1;
            }
         else
            {
                q->front++;
                if(q->front>=MAX_LEN) q->front=0;
            }
    return q;
}

element_t front(queue q){
    if (is_empty(q))
    {
        printf("ERROR. Queue is empty.\n");
        exit(1);
    }
    else
        return q->data[q->front];
}

element_t rear(queue q){
    if (is_empty(q))
    {
        printf("ERROR. Queue is empty.\n");
        exit(1);
    }
    else
        return q->data[q->rear];
}

void free_queue(queue q){
    free(q->data);
    free(q);
}
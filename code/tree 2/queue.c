#include<stdio.h>
#include<stdlib.h>

#include"queue.h"
queue creat_queue(){
    queue q = (queue) malloc (sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int is_empty(queue q){
    return ((q->front == q->rear) && (q->front == NULL));
}

int is_full(queue q){
    return 0;
}

node makenode(element_t x){
    node n = (node) malloc (sizeof(node));
    n->data = x;
    n->next = NULL;
    return n;
}

queue enqueue(queue q, element_t x){
    node n =makenode(x);
    if (is_empty(q)){
        q->front = n;
        q->rear = n;
        return q;
    }
    else
    {
        q->rear->next = n;
        q->rear = n;
        return q;
    }
}

queue dequeue(queue q){
    if (is_empty(q)){
        printf("ERROR. QUEUE IS EMPTY.\n");
        exit(1);
    }
    else if ( q->front == q->rear){
        q->front = NULL;
        q->rear = NULL;
        return q;
    }
    else
    {
        node n = q->front;
        q->front = q->front->next;
        free(n);
        return q;
    }  
}

element_t front(queue q){
    if (is_empty(q)){
        printf("ERROR. Queue is empty.\n");
        exit(1);
    }else
        return q->front->data;
}

element_t rear(queue q){
    if (is_empty(q)){
        printf("ERROR. Queue is empty.\n");
        exit(1);
    }else
        return q->rear->data;
}

void printqueue(queue q){
    node n;
    for (n= q->front; n != NULL; n = n->next)
        printf("%d\n", n->data);
}

int length(queue q){
    node n;
    int count = 0;
    for (n = q->front; n != NULL; n = n->next)
        count += 1;
    return count;
}

void free_queue(queue q){
    while (!is_empty(q))
    {
        q = dequeue(q);
    }
    free (q);
}
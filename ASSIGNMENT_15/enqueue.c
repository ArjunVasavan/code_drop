#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
    if(IsQueueFull(q) == SUCCESS){
        return FAILURE;
    }
    
    if(q->front == -1){
        q->front = 0;
    }
    
    q->rear = (q->rear + 1) % q->capacity;
    q->que[q->rear] = data;
    q->count++;
    
    return SUCCESS;
}
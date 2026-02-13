#include "queue.h"

/* Function to deque the element */
int dequeue(Queue_t *q)
{
    if(IsQueueEmpty(q) == SUCCESS){
        return FAILURE;
    }
    
    q->front = (q->front + 1) % q->capacity;
    q->count--;
    
    return SUCCESS;
}
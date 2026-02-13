#include "queue.h"

int IsQueueFull(Queue_t *q)
{
    //If the count of elements equals the capacity, it's full
    return (q->count == q->capacity) ? SUCCESS : FAILURE; 
}

int IsQueueEmpty(Queue_t *q)
{
    //If count is 0, the queue is empty
    return (q->count == 0) ? SUCCESS : FAILURE;
}
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1


typedef struct Que
{
    unsigned int capacity;
	int front, rear, count;
	int *que;
}Queue_t;
int create_queue(Queue_t *q, int size);
int enqueue(Queue_t *q, int data);
int dequeue(Queue_t *q);
int print_queue(Queue_t );
int IsQueueFull(Queue_t *q);
int IsQueueEmpty(Queue_t *q);

#endif
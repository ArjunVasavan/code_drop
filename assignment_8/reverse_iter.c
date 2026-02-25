#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head) 
{ 
    if ( *head == NULL ) return LIST_EMPTY;

    Slist* prev = NULL;
    Slist* curr = *head;
    Slist* next = NULL;

    while (curr != NULL ) {
    
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    return SUCCESS;

} 

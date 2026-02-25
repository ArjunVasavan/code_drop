#include "sll.h"

int reverse_recursion(Slist ** head, Slist* prev,Slist* curr, Slist* next)
{
    if ( *head == NULL ) return LIST_EMPTY;

    if (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        reverse_recursion(head,curr,next,next);

    } else {

        *head = prev;

    }

    return SUCCESS;
}

#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) { 

    if ( head == NULL )
        return LIST_EMPTY;

    if ( pos <= 0 )
        return FAILURE;

    Slist* fast = head;
    Slist* slow = head;


    // Moving Fast pointer POS ahead from slow
    for ( int i = 0 ; i < pos ; i++ ) {

        if ( fast == NULL ) {
            return FAILURE;
        }

        fast = fast->link;
    }
    // Moving both until fast reaches NULL
    while ( fast != NULL ) {
    
        slow = slow->link;
        fast = fast->link;

    }

    *data = slow->data;
    return SUCCESS;
} 

#include "sll.h"
#include <time.h>
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{ 
    if ( head == NULL ) return LIST_EMPTY;
    Slist *fast = head;
    Slist *slow = head;

    while ( fast != NULL && fast->link != NULL) {
    
        fast = (fast->link)->link;
        slow = slow->link;

    }
    *mid = slow->data;
    return SUCCESS;
} 

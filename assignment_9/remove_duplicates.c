#include "sll.h"

//remove duplicate data's from list
int remove_duplicates( Slist **head )
{
    if ( *head == NULL ) return FAILURE;

    Slist* t1 = *head;
    Slist* t2 = (*head)->link;
    Slist* prev = *head;

    while ( t1 != NULL && t1->link != NULL) {
    
        prev = t1;
        t2 = t1->link;

        while ( t2 != NULL) {
        
            if ( t1->data == t2->data ) {
                prev->link = t2->link;
                free( t2);
                t2 = prev->link;
            } else {
                prev = t2;
                t2 = t2->link;
            }

        }

        t1 = t1->link;

    }

    return SUCCESS;

}

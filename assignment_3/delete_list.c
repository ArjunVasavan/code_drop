#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{

    if ( *head == NULL ) return  FAILURE;

    Dlist* temp;

    while ( *head != NULL ) {
        temp = *head;
        *head = temp->next;
        free(temp);
    }

    *tail = NULL;
    return SUCCESS;

}

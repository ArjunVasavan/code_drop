#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    //case 1: empty list

    if ( *head == NULL && *tail == NULL ) {
        return FAILURE;
    }

    //case 2: [tail] == [head] i.e. single node

    if ( *head == *tail ) {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }

    //case 3: [head] != [tail] i.e. multiple nodes

    Dlist *temp = *head; // save old head
    *head = (*head)->next; // move head to next node
    ((*head)->next)->prev = NULL; // fix prev pointer
    free(temp); // free old head
    return SUCCESS;

}

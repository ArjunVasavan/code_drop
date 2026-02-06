#include "dll.h"
int dl_delete_last(Dlist **head, Dlist **tail)
{
    /* Case 1: Empty list */
    if (*head == NULL)
        return FAILURE;

    /* Case 2: Single node */
    if (*head == *tail) {
        free(*tail);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }

    /* Case 3: Multiple nodes */
    Dlist *temp = *tail;        // save old tail
    *tail = (*tail)->prev;      // move tail backward
    (*tail)->next = NULL;       // fix next pointer
    free(temp);                 // free old tail

    return SUCCESS;
}



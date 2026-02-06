#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = (Dlist*)malloc(sizeof(Dlist));

    if ( new_node == NULL ) {
        return FAILURE;
    }

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = data;

    if ( *head == NULL && *tail == NULL ) {
        *head = new_node;
        *tail = new_node;
        return SUCCESS;
    }

    new_node->next = *head;
    new_node->prev = NULL;
    (*head)->prev = new_node;
    *head = new_node;
    return SUCCESS;
}

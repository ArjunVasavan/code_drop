#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data) {

    Dlist* new_node = malloc(sizeof(Dlist));

    if ( new_node == NULL ) return FAILURE; 

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;


    if ( *head == NULL ) {
        *head = new_node;
        *tail = new_node;
        return  SUCCESS;
    }
    new_node->prev = *tail;
    (*tail)->next = new_node;
    (*tail) = new_node;
    return SUCCESS;
}

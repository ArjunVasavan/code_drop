#include "stack.h"

int Push(Stack_t **top, data_t data)
{
    if ( *top == NULL ) {
        *top = malloc(sizeof(Stack_t));
        if ( *top == NULL ) {
            return FAILURE;
        }
        (*top)->data = data;
        return SUCCESS;
    } 
    Stack_t* new_node = malloc(sizeof(Stack_t));
    if ( new_node == NULL ) {
        return FAILURE;
    }
    new_node->link = *top;
    new_node->data = data;
    *top = new_node;

    return SUCCESS;
}

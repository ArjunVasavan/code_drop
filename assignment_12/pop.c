#include "stack.h"

int Pop(Stack_t **top)
{
    if ( *top == NULL )
        return FAILURE;
    Stack_t* temp = *top;
    *top = (*top)->link;
    free(temp);
    return SUCCESS;
}

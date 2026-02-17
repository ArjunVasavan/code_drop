#include "sll.h"
int insert_sorted(Slist **head, data_t data)
{
    Slist *new_node = malloc(sizeof(Slist));
    if (new_node == NULL)
        return FAILURE;

    new_node->data = data;
    new_node->link = NULL;

    // Case 1: Empty list
    if (*head == NULL) {
        *head = new_node;
        return SUCCESS;
    }

    // Case 2: Insert at beginning
    if (data <= (*head)->data) {
        new_node->link = *head;
        *head = new_node;
        return SUCCESS;
    }

    // Case 3: Insert in middle or end
    Slist *prev = *head;
    Slist *curr = (*head)->link;

    while (curr != NULL && curr->data < data) {
        prev = curr;
        curr = curr->link;
    }

    new_node->link = curr;
    prev->link = new_node;

    return SUCCESS;
}


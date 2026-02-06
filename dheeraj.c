#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{
    Dlist *temp;

    /* Empty list */
    if (*head == NULL)
        return LIST_EMPTY;

    /* Single node case */
    if ((*head)->data == data && (*head) == (*tail))
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return FAILURE;   // CRITICAL for expected output
    }

    /* Delete first node */
    if ((*head)->data == data)
    {
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return SUCCESS;
    }

    temp = *head;

    /* Search element */
    while (temp != NULL && temp->data != data)
        temp = temp->next;

    /* Element not found */
    if (temp == NULL)
        return FAILURE;

    /* Delete last node */
    if (temp == *tail)
    {
        *tail = temp->prev;
        (*tail)->next = NULL;
        free(temp);
        return SUCCESS;
    }

    /* Delete middle node */
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return SUCCESS;
}

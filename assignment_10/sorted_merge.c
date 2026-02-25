#include "sll.h"

int sorted_merge(Slist **head1, Slist **head2)
{
    if (*head1 == NULL && *head2 == NULL)
    {
        return FAILURE;
    }

    // If list1 empty, make it list2
    if (*head1 == NULL)
    {
        *head1 = *head2;
        *head2 = NULL;
    }
    else if (*head2 != NULL)
    {
        // Go to end of list1
        Slist *temp = *head1;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        // Attach list2 to list1
        temp->link = *head2;
        *head2 = NULL;
    }

    // Now sort the combined list (Bubble sort style)
    Slist *i, *j;
    int temp_data;

    for (i = *head1; i != NULL; i = i->link)
    {
        for (j = i->link; j != NULL; j = j->link)
        {
            if (i->data > j->data)
            {
                temp_data = i->data;
                i->data = j->data;
                j->data = temp_data;
            }
        }
    }

    return SUCCESS;
}

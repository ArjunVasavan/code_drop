#include "sll.h"

int sl_sort(Slist **head)
{
    if (*head == NULL)
        return FAILURE;

    Slist *i_ptr = *head;
    Slist *j_ptr = NULL;

    while (i_ptr != NULL)
    {
        j_ptr = i_ptr->link;

        while (j_ptr != NULL)
        {
            if (i_ptr->data > j_ptr->data)
            {
                // swap data
                int temp = i_ptr->data;
                i_ptr->data = j_ptr->data;
                j_ptr->data = temp;
            }

            j_ptr = j_ptr->link;
        }

        i_ptr = i_ptr->link;
    }

    return SUCCESS;
}


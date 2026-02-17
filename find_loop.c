#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
    if (head == NULL)
        return FAILURE;

    Slist *slow = head;
    Slist *fast = head;

    while (fast != NULL && fast->link != NULL)
    {
        slow = slow->link;             // move 1 step
        fast = fast->link->link;       // move 2 steps

        if (slow == fast)              // loop detected
            return SUCCESS;
    }

    return FAILURE;   // no loop
}


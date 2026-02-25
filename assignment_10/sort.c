#include "sll.h"

void split_list(Slist *head, Slist **first, Slist **second ) {

    Slist* slow = head;
    Slist* fast = head->link;

    while ( fast && fast->link) {
    
        slow = slow->link;
        fast = fast->link->link;

    }

    *first = head;
    *second = slow->link;
    slow->link = NULL;
}

int sort(Slist **head)
{
    if ( *head == NULL || (*head)->link == NULL ) {
        return SUCCESS;
    }

    Slist* first = NULL;
    Slist* second = NULL;

    split_list(*head,&first,&second);

    *head = first;

    return SUCCESS;

}

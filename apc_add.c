#include<stdio.h>
#include "types.h"

int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **reshead,Dlist **restail)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int carry = 0;
    int data;

    while(temp1 || temp2)
    {
        if(temp1 && temp2)
        {
            if((data = temp1 -> data + temp2 -> data + carry) > 9)
            {
                carry = 1;
            }
            else
                carry = 0;
        }
        else if(temp1 == NULL && temp2 != NULL)
        {
             if((data = temp2 -> data + carry) > 9)
            {
                carry = 1;
            }
            else
                carry = 0;
        }
        else if(temp1 != NULL && temp2 == NULL)
        {
             if((data = temp1 -> data + carry) > 9)
            {
                carry = 1;
            }
            else
                carry = 0;
        }

        data = data % 10;
        insert_at_first(data,reshead,restail);

        if(temp1)
            temp1 = temp1 -> prev;
        if(temp2)
            temp2 = temp2 -> prev;
    }

    if(carry == 1)
    {
        insert_at_first(1,reshead,restail);
    }
}

int insert_at_first(int data,Dlist **head,Dlist **tail)
{
    Dlist *new = malloc(sizeof(Dlist));
    
    new -> data = data;
    new -> prev = NULL;
    new -> next = NULL;
    
    if(*head == NULL && *tail == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    
    new -> next = *head;
    new -> next -> prev = new;
    *head = new;
    return SUCCESS;
}

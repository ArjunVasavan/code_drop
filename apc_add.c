#include<stdio.h>
#include "types.h"

int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **reshead,Dlist **restail)
{
    int count = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int carry;
    
    Dlist *Rh1 = NULL;
    Dlist *Rt1 = NULL;
    Dlist *Rh2 = NULL;
    Dlist *Rt2 = NULL;
    Dlist *Rh3 = NULL;
    Dlist *Rt3 = NULL;

    while(temp2)
    {
        carry = 0;
        int data = 0;
        Rh2 = NULL;
        Rt1 = NULL;
        
        if(count != 0)
        {
            for(int i=0 ; i<count ; i++)
            {
                insert_at_first(0,&Rh2, &Rt2);
            }
        }
        temp1 = *tail1;

        while(temp1)
        {
            data = (temp1 -> data * temp2 -> data) + carry;
            carry = data / 10;
            data = data % 10;

            if(count==0)
            {
                insert_at_first(data,&Rh1, &Rt1);
            }
            else
            {
                insert_at_first(data,&Rh2, &Rt2);
            }

            temp1 = temp1->prev;
        
        }
            
        if(carry)
        {
            if (count == 0)
                insert_at_first(carry,&Rh1, &Rt1);
            else
                insert_at_first(carry,&Rh2, &Rt2);
        }

        if(count)
        {
            addition(&Rh1, &Rt1, &Rh2, &Rt2, &Rh3, &Rt3);
            delete_list(&Rh1, &Rt1);
            Rh1 = Rh3;
            Rt1 = Rt3;
            Rh3 = NULL;
            Rt3 = NULL;
            delete_list(&Rh2, &Rt2);
        }

        temp2 = temp2->prev;
        count++;       
    }

    *reshead = Rh1;
    *restail = Rt1;
    return SUCCESS;
}

int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL && *tail == NULL)
    {
        return FAILURE;
    }
    Dlist *temp = *head;
    while(temp != NULL)
    {
        Dlist *next = temp -> next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    if(*head == NULL){
        return LIST_EMPTY;
    }
    Slist *temp = *head;
    Slist *new = malloc(sizeof(Slist));
    if(!new){
        return FAILURE;
    }
    new->data = ndata;
    if((*head)->data == g_data){
        new->link = *head;
        *head = new;
        return SUCCESS;
    }
    while(temp->link != NULL){
        if(temp->link->data == g_data){
            new->link = temp->link;
            temp->link = new;
            return SUCCESS;
        }
        temp = temp->link;
    }
    free(new);
    return DATA_NOT_FOUND;
}

#include "sll.h"
#include <time.h>

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{ 
    if ( *head == NULL ) {
        Slist* new_node = malloc(sizeof(Slist));
        if (new_node == NULL ) return FAILURE;
        new_node->data = data;
        new_node->link = NULL;
        *head = new_node;
        return SUCCESS;
    }

    Slist* temp = *head;

    while (temp) {

        if ( ( temp->data >= data ) && (*head == temp) ) {
            Slist* new_node = malloc(sizeof(Slist));
            if (new_node == NULL ) return FAILURE;

            new_node->data = data;
            new_node->link = temp;
            *head = new_node;
            return SUCCESS;
        }

        if ( temp->data >= data ) {
            Slist* new_node = malloc(sizeof(Slist));
            if (new_node == NULL ) return FAILURE;

            new_node->data = data;
            new_node->link = temp->link;
            temp->link = new_node;
            return SUCCESS;
        }

        if ( temp->link == NULL ) {
            break;
        }

        temp = temp->link;
    }

    Slist* new_node = malloc(sizeof(Slist));
    if (new_node == NULL ) return FAILURE;

    new_node->data = data;
    new_node->link = NULL;
    temp->link = new_node;


    return SUCCESS;
} 

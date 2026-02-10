#include "../include/apc.h"

int ascii_to_int(char character ) {
    return character - 48; // 48 => '0'
}

/* NOTE: why **head **tail inspite of *head and *tail
 * if an function must change an pointer use pointer to pointer
 */
status create_list(char* argv, Dlist** head, Dlist** tail) {

    int i = 0;
    Dlist* temp = NULL;

    while (argv[i]) {

        Dlist* new_node = malloc(sizeof(Dlist));
        if ( new_node == NULL )
            return FAILURE; 

        new_node->data = ascii_to_int(argv[i]);
        new_node->next = NULL;

        if ( *head == NULL ) {
            new_node->prev = NULL;
            *head = new_node;
            *tail = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            new_node->prev = temp;
            *tail = new_node;
            temp = new_node;
        }
        i+=1;
    }
    return SUCCESS;
}

void print_list(Dlist* head,Dlist* tail) {

    if ( head == NULL ) {
        printf("List is empty\n");
        return;
    }

    printf("HEAD <-> ");

    Dlist* temp = head;

    while (temp!= NULL) {

        printf("%d",temp->data);
        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf(" <-> Tail\n");
}

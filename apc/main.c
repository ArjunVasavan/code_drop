#include "apc.h"

int main(int argc, char* argv[])
{
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL, *tailR=NULL;

	if(argc != 4){
		printf("ERROR: check the arguments\n");
		return FAILURE;
	}
    int neg1, neg2;
	digit_to_list(&head1, &tail1, argv[1], &neg1);
	digit_to_list(&head2, &tail2, argv[3], &neg2);

	char operator=argv[2][0];
    int status;
     printf("Result: ");
		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
                if (neg1 == 0 && neg2 == 0) {
                        // 24 + 4
                        addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                        //printf("Result: ");
                    } 
                    else if (neg1 == 1 && neg2 == 1) {
                        // -24 + -4 => -(24 + 4)
                        addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                        printf("-"); 
                    } 
                    else if (neg1 == 1 && neg2 == 0) {
                        // -24 + 4 => 4 - 24
                        status = subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                        //printf("Result: ");
                        if (status == 1) printf("-");
                    } 
                    else if (neg1 == 0 && neg2 == 1) {
                        // 24 + -4 => 24 - 4
                        status = subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                        //printf("Result: ");
                    if (status == 1) printf("-");
                    }
                    print_list(&headR, &tailR);
				    break;
			case '-':	
				/* call the function to perform the subtraction operation */
				if (neg1 == 1 && neg2 == 0) {
                    // Case: -24 - 24 => -(24 + 24)
                        printf("-"); 
                        addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    } else if (neg1 == 0 && neg2 == 1) {
                    // Case: 24 - (-24) => 24 + 24
                        addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    } else if (neg1 == 1 && neg2 == 1) {
                    // Case: -24 - (-24) => -24 + 24 => 24 - 24
                        subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                    } else {
                        // Standard positive subtraction
                        status = subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    if (status == 1) printf("-");
                    }
                print_list(&headR, &tailR);
				break;
			case 'X':	
				/* call the function to perform the multiplication operation */
		
                // Rule: Unlike signs = Negative, Like signs = Positive
                if (neg1 != neg2) {
                        // If one is negative and the other is positive
                    if(!((head1->data == 0 && head1->next == NULL) || 
                            (head2->data == 0 && head2->next == NULL))) { 
                        printf("-"); 
                        }
                    }
                multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                print_list(&headR, &tailR);
				break;
			case '/':	
				/* call the function to perform the division operation */
                if(head2->data == 0 && head2->next == NULL){
                    printf("Error: Division by zero is not allowed.\n");
                    break;
                }
                if(neg1 != neg2){
                    if(compare(head1, head2) != -1){
                        printf("-");
                    }
                }
				if(division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS){
                print_list(&headR, &tailR);
                }
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
    
	return 0;
}

int ascii_to_int(char character ) {
    return character - 48; // 48 => '0'
}

// Add a parameter to capture if the number is negative
int digit_to_list(Dlist **head, Dlist **tail, char *argv, int *is_neg) {
    int i = 0;
    *is_neg = 0;

    if (argv[0] == '-') {
        *is_neg = 1;
        i = 1; // Start processing digits from the next character
    }

    while (argv[i]) {
        Dlist* new_node = malloc(sizeof(Dlist));
        if (new_node == NULL) return FAILURE;

        new_node->data = ascii_to_int(argv[i]);
        new_node->next = NULL;

        if (*head == NULL) {
            new_node->prev = NULL;
            *head = new_node;
            *tail = new_node;
        } else {
            (*tail)->next = new_node;
            new_node->prev = *tail;
            *tail = new_node;
        }
        i++;
    }
    return SUCCESS;
}

void print_list(Dlist **head, Dlist **tail) {
    if (*head == NULL) {
        printf("0\n"); 
        return;
    }

    Dlist *temp = *head;

    // Skip leading zeros
    while (temp->next != NULL && temp->data == 0) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next; 
    }
    printf("\n"); // New line only at the very end
}
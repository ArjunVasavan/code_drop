#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    // 1. Division by zero check
    if ((*head2)->data == 0 && (*head2)->next == NULL) return FAILURE;

    // 2. Initialize Quotient to 0
    Dlist *hQ = NULL, *tQ = NULL;
    insert_at_first(0, &hQ, &tQ);
    
    // Constant 1 for incrementing
    Dlist *hOne = NULL, *tOne = NULL;
    insert_at_first(1, &hOne, &tOne);

    // Working copies
    Dlist *curH1 = *head1, *curT1 = *tail1;

    // 3. The Loop
    // Ensure compare returns 1 (Greater) or 0 (Equal) to continue
    while (compare(curH1, *head2) >= 0) {
		//printf("head data: %d\n", curH1->data);
        Dlist *nextH = NULL, *nextT = NULL;
        
        // Subtract: next = current - divisor
        subtraction(&curH1, &curT1, head2, tail2, &nextH, &nextT);
        
        // UPDATE: This is where it usually fails. 
        // We must point to the NEW result of the subtraction.
        curH1 = nextH;
        curT1 = nextT;

        // Increment Quotient: Q = Q + 1
        Dlist *newHQ = NULL, *newTQ = NULL;
        addition(&hQ, &tQ, &hOne, &tOne, &newHQ, &newTQ);
        hQ = newHQ;
        tQ = newTQ;
        
        // Safety check: if result is 0, we are done
        if (curH1->data == 0 && curH1->next == NULL) break;
    }

    *headR = hQ;
    *tailR = tQ;
    return SUCCESS;
}
#include "main.h"

int perform_operation(char op, int op1, int op2) {
    switch(op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default:  return 0;
    }
}

int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
    int i = 0;
    
    while (Postfix_exp[i] != '\0') {
        char ch = Postfix_exp[i];
        
        // If operand (digit), push its integer value
        if (isdigit(ch)) {
            push(stk, ch - '0');  // Convert char '5' to int 5
        }
        // If operator, pop 2 operands, compute, push result
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = peek(stk);
            pop(stk);
            int operand1 = peek(stk);
            pop(stk);
            int result = perform_operation(ch, operand1, operand2);
            push(stk, result);
        }
        i++;
    }
    
    // Final result is at top of stack
    return peek(stk);
}

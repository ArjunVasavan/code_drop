#include "main.h"
#include <ctype.h>

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
    int i = 0, j = 0;
    
    while (Infix_exp[i] != '\0') {
        char ch = Infix_exp[i];
        
        // Operand - copy directly to postfix
        if (isalnum(ch)) {
            Postfix_exp[j++] = ch;
        }
        // Left parenthesis - push to stack
        else if (ch == '(') {
            push(stk, ch);
        }
        // Right parenthesis - pop until left parenthesis
        else if (ch == ')') {
            while (peek(stk) != -1 && peek(stk) != '(') {
                Postfix_exp[j++] = peek(stk);
                pop(stk);
            }
            if (peek(stk) != -1) {
                pop(stk);  // Remove '('
            }
        }
        // Operator - check precedence
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (peek(stk) != -1 && peek(stk) != '(' && 
                   priority(peek(stk)) >= priority(ch)) {
                Postfix_exp[j++] = peek(stk);
                pop(stk);
            }
            push(stk, ch);
        }
        i++;
    }
    
    // Pop remaining operators
    while (peek(stk) != -1) {
        Postfix_exp[j++] = peek(stk);
        pop(stk);
    }
    
    Postfix_exp[j] = '\0';
    return 0;
}

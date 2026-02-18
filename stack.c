#ifndef MAIN_H
#define MAIN_H

#define MAX 100

typedef struct stack
{
    int stack[MAX];
    int top;
} Stack_t;

/* stack functions */
int push(Stack_t *stk, int data);
int pop(Stack_t *stk);
int peek(Stack_t *stk);
int priority(char opr);

/* conversion */
int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk);

/* evaluation */
int Prefix_Eval(char *Prefix_exp, Stack_t *stk);

/* utility */
void strrev(char *str);

#endif
 A14 main.h
#include "main.h"
#include <stdio.h>

int main()
{
    char Infix_exp[100];
    char Prefix_exp[100];
    Stack_t stk;

    printf("Enter the Infix expression : ");
    scanf("%s", Infix_exp);

    Infix_Prefix_conversion(Infix_exp, Prefix_exp, &stk);

    printf("PreFix expression : %s\n", Prefix_exp);

    int result = Prefix_Eval(Prefix_exp, &stk);

    printf("Result : %d\n", result);

    return 0;
}

A14:main.c 
#include "main.h"
#include <ctype.h>
#include <string.h>

/* string reverse */
void strrev(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
    char rev[100];
    int i, j = 0;

    strcpy(rev, Infix_exp);
    strrev(rev);

    /* swap brackets */
    for (i = 0; rev[i]; i++)
    {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    stk->top = -1;

    for (i = 0; rev[i]; i++)
    {
        char ch = rev[i];

        if (isalnum(ch))
        {
            Prefix_exp[j++] = ch;
        }
        else if (ch == '(')
        {
            push(stk, ch);
        }
        else if (ch == ')')
        {
            while (stk->top != -1 && peek(stk) != '(')
                Prefix_exp[j++] = pop(stk);

            if (stk->top != -1)
                pop(stk);
        }
        else
        {
            while (stk->top != -1 &&
                   peek(stk) != '(' &&
                   priority(peek(stk)) > priority(ch))
            {
                Prefix_exp[j++] = pop(stk);
            }
            push(stk, ch);
        }
    }

    while (stk->top != -1)
        Prefix_exp[j++] = pop(stk);

    Prefix_exp[j] = '\0';

    strrev(Prefix_exp);
    return 0;
}
A14 infix_pre
#include "main.h"
#include <ctype.h>
#include <string.h>

int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
    stk->top = -1;

    int i = strlen(Prefix_exp) - 1;

    while (i >= 0)
    {
        char ch = Prefix_exp[i];

        if (isdigit(ch))
        {
            push(stk, ch - '0');
        }
        else
        {
            int op1 = pop(stk);
            int op2 = pop(stk);

            int result;

            switch(ch)
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^':
                {
                    result = 1;
                    for(int k = 0; k < op2; k++)
                        result *= op1;
                    break;
                }
                default: return -1;
            }

            push(stk, result);
        }
        i--;
    }

    return pop(stk);
}
A14: pref_eval
#include "main.h"

/* PUSH */
int push(Stack_t *stk, int data)
{
    if (stk->top == MAX - 1)
        return 0;

    stk->stack[++stk->top] = data;
    return 1;
}

/* POP */
int pop(Stack_t *stk)
{
    if (stk->top == -1)
        return -1;

    return stk->stack[stk->top--];
}

/* PEEK */
int peek(Stack_t *stk)
{
    if (stk->top == -1)
        return -1;

    return stk->stack[stk->top];
}

/* PRIORITY */
int priority(char opr)
{
    switch(opr)
    {
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 2;

        case '^': return 3;

        default: return 0;
    }
}

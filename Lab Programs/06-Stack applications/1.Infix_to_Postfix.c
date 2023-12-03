#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 100

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; // for non-operators
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char stack[size];
    int top = -1; // Initialize the stack top

    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            stack[++top] = infix[i];
        else if (isOperator(infix[i]))
        {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(infix[i]))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--; // Pop the '(' from the stack
        }
    }

    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main()
{
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

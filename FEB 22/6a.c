#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define n 100

// Stack implementation
typedef struct
{
    int top;
    int items[n];
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, int value)
{
    if (s->top == n - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    Stack stack;
    initialize(&stack);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(&stack, postfix[i] - '0');
        }
        else
        {
            float operand2 = pop(&stack);
            float operand1 = pop(&stack);

            switch (postfix[i])
            {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                case '^':
                    push(&stack, (float)pow(operand1, operand2));
                    break;
                default:
                    printf("Invalid character in postfix expression\n");
                    exit(1);
            }
        }
    }

    return pop(&stack);
}

int main()
{
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    float result = evaluatePostfix(postfix);
    printf("Result: %f\n", result);

    return 0;
}

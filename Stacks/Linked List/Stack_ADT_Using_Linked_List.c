#include <stdio.h>
#include <stdlib.h>
int x;
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

int isempty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
void push(int x)
{
        struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
        if (tmp == NULL)
        {
            printf("Stack Overflow\n");
            return;
        }
        tmp->data = x;
        tmp->next = top;
        top = tmp;
}
void pop()
{
    if (isempty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node *tmp = top;
    x = top->data;
    top = top->next;
    free(tmp);
    printf("The Poped Element is:%d\n", x);
}
void peek()
{
    if (isempty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    printf("The Peek Element is:\n");
    printf("%d\n", top->data);
}
void dispaly()
{
    if (isempty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack Elements Are:\n");
        struct Node *p = top;
        while (p != NULL)
        {
            printf("%d\n", p->data);
            p = p->next;
        }
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter The Element To Be Pushed:\n");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            dispaly();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
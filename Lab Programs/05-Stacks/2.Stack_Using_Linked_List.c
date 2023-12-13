#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

int isempty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
void push(int element)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=top;
    top=newnode;
}
void pop()
{
    if(isempty())
    {
        printf("Stack Underflow");
        return;
    }
    else
    {
        struct node *temp=top;
        printf("Popped element is %d",temp->data);
        top=top->next;
        free(temp);
    }
}
void peek()
{
    if(isempty())
    {
        printf("Stack Underflow");
        return;
    }
    else
    {
        printf("Top element is %d",top->data);
    }
}
void display()
{
    if(isempty())
    {
        printf("Stack Underflow");
        return;
    }
    else
    {
        struct node *temp=top;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int choice,element;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element to be pushed:");
                   scanf("%d",&element);
                   push(element);
                   break;
            case 2:pop();
                   break;
            case 3:peek();
                   break;
            case 4:display();
                   break;
            case 5:exit(0);
            default:printf("Invalid Choice");
        }
    }
    return 0;
}
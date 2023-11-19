#include<stdio.h>
#include<stdlib.h>
#define n 5
int arr[n];
int top=-1;
int element;
int isfull()
{
    if(top==n-1)
        return 1;
    else    
        return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int element)
{
    if(isfull())
    {
        printf("Stack Overflow");
    }
    else
    {
        top=top+1;
        arr[top]=element;
    }
}
void pop()
{
    if(isempty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    printf("The Poped Element is:%d",arr[top]);
    top=top-1;
}
void peek()
{
    if(isempty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
        printf("The Peek Element is:%d",arr[top]);
}
void display()
{
    if(isempty())
    {
        printf("Stack is Empty");
    }
    printf("Stack Elements are:");
    for(int i=top;i>=0;i--)
        printf("%d\t",arr[i]);
}
int main()
{
    int choice,element;
    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");

        printf("\nEnter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter The Element to Push:");
                scanf("%d",&element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Invalid Choice");
        }

    }
}
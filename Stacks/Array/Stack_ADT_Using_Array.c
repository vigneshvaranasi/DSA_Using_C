#include<stdio.h>
#include<stdlib.h>
#define n 5
int arr[n];
int top=-1;
int x;
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
void push(int x)
{
    if(isfull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top=top+1;
        arr[top]=x;
    }
}
void pop()
{
    if(isempty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    x=arr[top];
    top=top-1;
    printf("The Poped Element is:%d\n",x);
}
void peek()
{
    if(isempty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    printf("The Peek Element is:\n");
    printf("%d\n",arr[top]);
}
void dispaly()
{
    if(isempty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack Elements Are:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",arr[i]);
        }
    }
}
int main()
{
    int ch;
    printf("Stack ADT Using Array\n");
    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter The Element To Push:\n");
                scanf("%d",&x);
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

	

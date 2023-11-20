#include<stdio.h>
#include<stdlib.h>
#define n 5
int queue[n];
int front=-1;
int rear=-1;

int isempty()
{
    if(front ==-1 || front>rear)
        return 1;
    else 
        return 0;
}
int isfull()
{
    if(rear==n-1)
        return 1;
    else 
        return 0;
}

void enqueue(int element)
{
    if(rear==-1 && front==-1)
    {
        front=rear=0;
        queue[rear]=element;
    }
    else if(isfull())
    {
        printf("Queue is full Cannot Palce the Element in the queue\n");
    }
    else
    {
        rear++;
        queue[rear]=element;
    }
}
void dequeue()
{
    if(isempty())
    {
        printf("Queue Underflow");
        front=rear=-1;
    }
    else
    {
        printf("The Dequeued Element is:%d",queue[front]);
        front++;
    }
}
void peek()
{
    if(isempty())
        printf("Queue Empty");
    else
    {
        printf("The Peak Element is:%d",queue[front]);
    }
}
void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
}
int main()
{
    int choice,x;
    while(1)
    {
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Element to Enqueue:");
            scanf("%d",&x);
            enqueue(x);
            break;
        case 2:
            dequeue();
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
            printf("Enter Correct Choice!");
            break;
        }
    }
}
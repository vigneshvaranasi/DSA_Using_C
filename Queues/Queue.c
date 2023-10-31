#include<stdio.h>
#define n 5
int queue[n];
int front=-1;
int rear=-1;
void enqueue(int x)
{
    if(rear==n-1)
    {
        printf("Queue is full");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The deleted element is %d",queue[front]);
        front++;
    }
}
void display()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}
void peek()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The peek element is %d",queue[front]);
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    peek();
    return 0;
}
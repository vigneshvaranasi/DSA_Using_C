#include <stdio.h>
int queue[10];
int front = -1; // initially no item is present in the queue
int rear = -1;  // initially no item is present in the queue
void enqueue(int x)
{
    if (rear == -1 && front == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
int dequeue()
{
    int x = -1;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow");
    }
    else
    {
        x = queue[front++];
    }
    return x;
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
    enqueue(5);
    enqueue(3);
    enqueue(7);
    enqueue(2);
    peek();
    printf("%d\n", dequeue());
    peek();
    printf("%d\n", dequeue());
    peek();
    printf("%d\n", dequeue());
    peek();
    printf("%d\n", dequeue());
    peek();
    return 0;
}
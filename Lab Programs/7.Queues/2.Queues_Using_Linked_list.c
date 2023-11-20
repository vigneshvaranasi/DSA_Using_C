#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*newnode,*ptr;
int isempty()
{
    if(front==NULL)
        return 1;
    else
        return 0;
}
void enqueue(int element)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
        front->data=element;
        front->next=NULL;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->data=element;
        rear->next=NULL;
    }
}
void dequeue()
{
    if(isempty())
    {
        printf("Queue is Empty");
    }
    else
    {
        ptr=front;
        printf("%d is removed from queue\n",ptr->data);
        front=front->next;
        free(ptr);
    }
}
void peek()
{
    if(isempty())
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Front of the Queue = %d \n",front->data);
    }
}
void display()
{
    ptr=front;
    if(isempty())
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("The Queue Elements are:");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
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
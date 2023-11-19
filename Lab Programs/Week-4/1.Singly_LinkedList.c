#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *newnode,*temp;
struct node *ptr;

void read(int n)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=0;
    if(head==0)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}
void display()
{
    ptr=head;
    if(head==0)
    {
        printf("Linked List is Empty.");
        exit(0);
    }
    while(ptr!=0)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
void search(int element)
{
    ptr=head;
    int pos=1;
    if(head==0)
    {
        printf("LInked List is Empty.");
        exit(0);
    }
    while(ptr!=0)
    {
        if(element == ptr->data)
        {
            printf("Element Found at position:%d",pos);
            return;
        }
        ptr=ptr->next;
        pos=pos+1;
    }
    printf("Element Not found in the Linked list");
       
}
void insertfirst(int element)
{
    ptr=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=head;
    head=newnode;
}
void insertend(int element)
{
    ptr=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=0;
    while(ptr->next!=0)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
}
void insertafternode(int element,int item)
{
    ptr=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    while(ptr->next!=0)
    {
        if(ptr->data==item)
        {
            newnode->next=ptr->next;
            ptr->next=newnode;
        }
        ptr=ptr->next;
    }

}
void insertbeforenode(int element,int item)
{
    ptr=head;
    if(head->data=item)
        insertfirst(element);
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=element;
        while(ptr->next!=0)
        {
            if(ptr->next->data==item)
            {
                newnode->next=ptr->next;
                ptr->next=newnode;
            }
            ptr=ptr->next;
        }
        printf("Node with data %d not found in the Linked list\n", item);
    }
}

int main()
{
    int choice;
    int n,c,item;
    do{
        printf("Enter Elements:");
        scanf("%d",&n);
        read(n);
        printf("Do you Want to continue(0 0r 1):");
        scanf("%d",&c);
    }
    while(c);
    do{
        printf("\n1.Insert First");
        printf("\n2.Display");
        printf("\n3.Search");
        printf("\n4.Insert at End");
        printf("\n5.Insert After Node");
        printf("\n6.Insert Before Node");
        printf("\n10.Exit");
        printf("\nEnter Choice to Perform Action:");

        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element to Insert:");
            scanf("%d",&n);
            insertfirst(n);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter Element to Search:");
            scanf("%d",&n);
            search(n);
            break;
        case 4:
            printf("Enter Element to Insert:");
            scanf("%d",&n);
            insertend(n);
            break;
        case 5:
            printf("Enter Node:");
            scanf("%d",&item);
            printf("Enter Element to Insert:");
            scanf("%d",&n);
            insertafternode(n,item);
            break;
        case 6:
            printf("Enter Node:");
            scanf("%d",&item);
            printf("Enter Element to Insert:");
            scanf("%d",&n);
            insertbeforenode(n,item);
            break;
        case 10:
            exit(0);
        
        default:
            printf("\nEnter Correct Choice.");
            break;
        }
    }
    while(1);
}
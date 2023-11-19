#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *newnode,*temp;
head=0;
void insert(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(head=0)
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
    temp=head;
}
int main()
{   
    int n;
    printf("Enter Data to insert:");
    scanf("%d",&n);
    insert(n);
    insert(4);
    display();
}
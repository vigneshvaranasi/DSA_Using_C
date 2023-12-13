#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *newnode, *temp;
struct node *ptr;

void read(int n)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
int main()
{
    int choice;
    int n, c, count=0;
    do
    {
        printf("Enter Elements:");
        scanf("%d", &n);
        read(n);
        printf("Do you Want to continue(0 0r 1):");
        scanf("%d", &c);
    } while (c!= 0);

    ptr = head;
    if (head == 0)
    {
        printf("Linked List is Empty.");
        exit(0);
    }
    printf("Given Linked List is:");
    while (ptr != 0)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\nNumber of Nodes in given Linked List is:%d",count);


}

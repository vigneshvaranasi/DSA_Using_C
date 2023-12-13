#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        newnode->prev = 0;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void display()
{
    ptr = head;
    if (head == 0)
    {
        printf("Linked List is Empty.");
        exit(0);
    }
    while (ptr != 0)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
void insertfirst(int element)
{
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = 0;
    newnode->data = element;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insertafternode(int element, int item)
{
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    while (ptr != 0)
    {
        if (ptr->data == item)
        {
            newnode->next = ptr->next;
            ptr->next->prev = newnode;
            newnode->prev = ptr;
            ptr->next = newnode;
        }
        ptr = ptr->next;
    }
}
void deletefirst()
{
    ptr = head;
    head = ptr->next;
    head->prev = 0;
    printf("The Deleted Element is:%d", ptr->data);
    free(ptr);
}
void deletespecifiednode(int item)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->data == item)
    {
        deletefirst();
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                if (ptr->next != NULL)
                {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }
                else
                {
                    ptr->prev->next = NULL;
                }

                printf("The Deleted Element is:%d\n", ptr->data);
                free(ptr);
                return;
            }
            ptr = ptr->next;
        }

        printf("Element %d not found in the list.\n", item);
    }
}

int main()
{
    int choice;
    int n, c, item, pos;
    do
    {
        printf("Enter Elements:");
        scanf("%d", &n);
        read(n);
        printf("Do you Want to continue(0 0r 1):");
        scanf("%d", &c);
    } while (c);
    do
    {
        printf("\n1.Display");
        printf("\n2.Insert First");
        printf("\n3.Insert After Node");
        printf("\n4.Delete Specified Node");
        printf("\n5.Exit");
        printf("\nEnter Choice to Perform Action:");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            printf("Enter Element to Insert:");
            scanf("%d", &n);
            insertfirst(n);
            break;
        case 3:
            printf("Enter Node:");
            scanf("%d", &item);
            printf("Enter Element to Insert:");
            scanf("%d", &n);
            insertafternode(n, item);
            break;
        case 4:
            printf("Enter Node to delete:");
            scanf("%d", &item);
            deletespecifiednode(item);
            break;
        case 5:
            exit(0);

        default:
            printf("\nEnter Correct Choice.");
            break;
        }
    } while (1);
}

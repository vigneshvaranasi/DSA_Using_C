#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void traverse(struct Node *head)
{
    struct Node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void search(struct Node *head,int key)
{
    struct Node *p = head;
    while (p != NULL)
    {
        if(p->data==key)
        {
            printf("Key found");
            return;
        }
        p = p->next;
    }
    printf("Key not found");
}
insertfirst(head,x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=first;
    first=t;
}
insertlast(head,x)
{
    struct Node *t,*p;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
    }
    else
    {
        p=first;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}

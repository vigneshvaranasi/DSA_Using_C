#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

void isempty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
void push(int element)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode=NULL)
    {
        printf("Stack Overflow");
        return;   
    }
    newnode->data=element;
    newnode->next=top;
    
}
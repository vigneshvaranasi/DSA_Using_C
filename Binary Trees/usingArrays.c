#include<stdio.h>
#define totalnodes 15
char tree[totalnodes+1];
int getLeftChild(int index)
{
    int leftchild=2*index;
    return (leftchild<=totalnodes) ? leftchild:-1;
    
}
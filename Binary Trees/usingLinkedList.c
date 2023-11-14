#include<stdio.h>
struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
};
struct treenode *newNode(int data)
{
    struct treenode* node=(struct treenode*)malloc(sizeof(struct treenode));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
};

int main()
{

}
#include<stdio.h>
#include<stdlib.h>
struct Treenode
{
    int data;
    struct Treenode *left;
    struct Treenode *right;
};
struct Treenode* newnode(int element)
{
    struct Treenode* node=(struct Treenode*)malloc(sizeof(struct Treenode));
    node->data=element;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void inorder(struct Treenode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct Treenode* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Treenode* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    struct Treenode* root=newnode(10);
    root->left=newnode(7);
    root->right=newnode(15);
    root->left->left=newnode(5);
    root->right->left=newnode(12);
    root->right->right=newnode(20);
    root->left->left->right=newnode(8);

    printf("In Order: ");
    inorder(root);
    printf("\nPre Order: ");
    preorder(root);
    printf("\nPost Order: ");
    postorder(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void preOrder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct TreeNode* root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(15);
    root->left->left = newNode(5);
    root->right->left = newNode(12);
    root->right->right = newNode(20);
    root->left->left->right = newNode(8);
    printf("In Order: ");
    inOrder(root);
    printf("\n");
    printf("Pre Order: ");
    preOrder(root);
    printf("\n");
    printf("Post Order: ");
    postOrder(root);
    printf("\n");
    return 0;
}
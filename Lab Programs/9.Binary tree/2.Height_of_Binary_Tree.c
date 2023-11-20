#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findHeight(struct TreeNode* root) {
    if (root == NULL) {
        return -1; 
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        // Return the height of the taller subtree, plus 1 for the current level
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->left->left= createNode(5);

    int height = findHeight(root);

    printf("Height of the binary tree: %d\n", height);

    return 0;
}

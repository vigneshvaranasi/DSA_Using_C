#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct BinaryTree {
    struct TreeNode* root;
};
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(struct BinaryTree* tree, int data) {
    struct TreeNode* newNode = createNode(data);
    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        struct TreeNode* current = tree->root;
        while (1) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }
}
struct TreeNode* removeNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = removeNode(root->left, data);
    } else if (data > root->data) {
        root->right = removeNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}


int main() {
    struct BinaryTree binaryTree;
    binaryTree.root = NULL;

    int choice, data;

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&binaryTree, data);
                break;

            case 2:
                printf("Enter data to remove: ");
                scanf("%d", &data);
                binaryTree.root = removeNode(binaryTree.root, data);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
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
struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
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
int search(struct TreeNode* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
int findLevel(struct TreeNode* root, int data, int level) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == data) {
        return level;
    }
    int leftLevel = findLevel(root->left, data, level + 1);
    if (leftLevel != -1) {
        return leftLevel;
    }
    return findLevel(root->right, data, level + 1);
}
int size(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
int main() {
    struct BinaryTree binaryTree;
    binaryTree.root = NULL;

    int choice, data;

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Find Height\n");
        printf("6. Find Level of a Node\n");
        printf("7. Find Size\n");
        printf("8. Exit\n");
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
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(binaryTree.root, data)) {
                    printf("Data found in the tree.\n");
                } else {
                    printf("Data not found in the tree.\n");
                }
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(binaryTree.root);
                printf("\n");
                break;

            case 5:
                printf("Height of the tree: %d\n", height(binaryTree.root));
                break;

            case 6:
                printf("Enter data to find its level: ");
                scanf("%d", &data);
                int level = findLevel(binaryTree.root, data, 1);
                if (level != -1) {
                    printf("Level of %d: %d\n", data, level);
                } else {
                    printf("Node not found in the tree.\n");
                }
                break;

            case 7:
                printf("Size of the tree: %d\n", size(binaryTree.root));
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct BinaryTree
{
    struct TreeNode *root;
};
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(struct BinaryTree *tree, int data)
{
    if (tree->root == NULL)
    {
        tree->root = createNode(data);
        return;
    }
    struct TreeNode *current = tree->root;
    while (1)
    {
        if (data < current->data)
        {
            // If the left child is NULL, insert the new node here
            if (current->left == NULL)
            {
                current->left = createNode(data);
                return;
            }
            // Otherwise, move to the left child
            current = current->left;
        }
        // If the data is greater than or equal to the current node, move to the right subtree
        else
        {
            // If the right child is NULL, insert the new node here
            if (current->right == NULL)
            {
                current->right = createNode(data);
                return;
            }
            // Otherwise, move to the right child
            current = current->right;
        }
    }
}
struct TreeNode *findMin(struct TreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
struct TreeNode *removeNode(struct TreeNode *root, int data)
{
    if (root == NULL)
        return NULL;
    if (data < root->data)
        root->left = removeNode(root->left, data);
    else if (data > root->data)
        root->right = removeNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main()
{
    struct BinaryTree binaryTree;
    binaryTree.root = NULL;

    int choice, data;

    do
    {
        printf("\nBinary Tree Operations:\n");
        printf("1.Insert\n");
        printf("2.Remove\n");
        printf("3.Inorder Traversal\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
            printf("Inorder Traversal: ");
            inorderTraversal(binaryTree.root);
            printf("\n");
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
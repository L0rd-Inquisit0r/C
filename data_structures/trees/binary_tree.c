#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef int ElementType;

typedef struct node {
    ElementType data;
    struct node *left;
    struct node *right;
} Node, *NodePtr;

typedef NodePtr BST;

// Core API
void initTree(BST *root);
void freeTree(BST *root);
void insertElem(BST *root, ElementType val);
void deleteElem(BST *root, ElementType val);
bool search(BST root, ElementType val);

// Traversal API
void preOrder(BST root);
void inOrder(BST root);
void postOrder(BST root);

// Utility
ElementType findMin(BST root);
ElementType findMax(BST root);
bool isEmpty(BST root);

// Internal helper
static NodePtr createNode(ElementType val) {
    NodePtr newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("CRITICAL ERROR: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main(void) {
    BST tree;
    initTree(&tree);

    // Build BST
    insertElem(&tree,6);
    insertElem(&tree,2);
    insertElem(&tree,3);
    insertElem(&tree,9);
    insertElem(&tree,1);
    insertElem(&tree,8);
    insertElem(&tree,7);
    insertElem(&tree,10);
    insertElem(&tree,5);
    insertElem(&tree,4);

    printf("Pre-Order  : ");
    preOrder(tree);
    printf("\nIn-Order   : ");
    inOrder(tree);
    printf("\nPost-Order : ");
    postOrder(tree);
    printf("\n\n");

    printf("Minimum element: %d\n", findMin(tree));
    printf("Maximum element: %d\n", findMax(tree));

    printf("\nDeleting node 2 (Node with 2 children)...\n");
    deleteElem(&tree, 2);

    printf("In-Order after deletion: ");
    inOrder(tree);
    printf("\n");

    freeTree(&tree);
    return 0;
}

void initTree(BST* root) {
    *root = NULL;
}

void freeTree(BST *root) {
    if (*root != NULL) {
        freeTree(&((*root)->left));   
        freeTree(&((*root)->right));
        free(*root);
        *root = NULL;   
    }
}

void insertElem(BST *root, ElementType val) {
    BST *trav = root;

    while (*trav != NULL) {
        if (val < (*trav)->data) {
            trav = &((*trav)->left);
        } else if (val > (*trav)->data) {
            trav = &((*trav)->right);
        } else {
            // Duplicate values ignored in standard BST
            return;
        }
    }

    *trav = createNode(val);
}

void deleteElem(BST* root, ElementType val) {
    BST *trav = root;
    
    while (*trav != NULL && (*trav)->data != val) {
        if (val < (*trav)->data) {
            trav = &((*trav)->left);
        } else {
            trav = &((*trav)->right);
        }
    }

    if (*trav == NULL) {
        printf("WARNING: Element %d not found in tree.\n", val);
        return; // Element not found
    }

    NodePtr del = *trav;

    // Case 1 & 2: 0 or 1 Child
    if ((*trav)->left == NULL) {
        *trav = (*trav)->right;
        free(del);
    } else if ((*trav)->right == NULL) {
        *trav = (*trav)->left;
        free(del);
    } else {
        // Case 3: 2 Children
        // Find in-order successor (minimum node in right subtree)
        BST *succ = &((*trav)->right);
        while ((*succ)->left != NULL) {
            succ = &((*succ)->left);
        }

        // Copy successor value to current node
        (*trav)->data = (*succ)->data;

        // Delete the successor node
        del = *succ;
        *succ = (*succ)->right;
        free(del);
    }
}

bool search(BST root, ElementType val) {
    while (root != NULL) {
        if (val == root->data) return true;
        root = (val < root->data) ? root->left : root->right;
    }
    return false;
}

void preOrder(BST root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BST root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void postOrder(BST root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

ElementType findMin(BST root) {
    if (isEmpty(root)) {
        printf("ERROR: Tree is empty.\n");
        return INT_MIN;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

ElementType findMax(BST root) {
    if (isEmpty(root)) {
        printf("ERROR: Tree is empty.\n");
        return INT_MAX;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

bool isEmpty(BST root) {
    return root == NULL;
}
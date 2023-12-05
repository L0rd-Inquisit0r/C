#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int val;
    struct node *L;
    struct node *R;
}NODE,*BST;

void initTree(BST* T);
void nullTree(BST* T);
NODE createNode();
void insert(BST* T,int val);
int delete(BST* T,int val);
void preOrder(BST T);
void inOrder(BST T);
void postOrder(BST T);
int max(BST T);
int min(BST T);

int main()
{

    return 0;
}


#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int val;
    struct node *L;
    struct node *R;
}NODE,*BST;

void initTree(BST* root);
void nullTree(BST* root);
BST createNode();

void insert(BST* root,int val);
int delete(BST* root,int val);
void preOrder(BST root);
void inOrder(BST root);
void postOrder(BST root);
int max(BST root);
int min(BST root);

int main()
{
    BST tree;

    initTree(&tree);

    insert(&tree,6);
    insert(&tree,2);
    insert(&tree,3);
    insert(&tree,9);
    insert(&tree,1);
    insert(&tree,8);
    insert(&tree,7);
    insert(&tree,10);
    insert(&tree,5);
    insert(&tree,4);

    preOrder(tree);
    printf("\n");
    inOrder(tree);
    printf("\n");
    postOrder(tree);
    printf("\n");

    return 0;
}

void initTree(BST* root)
{
    *root=NULL;
}

BST createNode()
{
    BST node=(BST)malloc(sizeof(NODE));
    node->L=node->R=NULL;

    return node;
}

void insert(BST* root,int val)
{
    BST leaf;
    BST *trav,*next;
    for(trav=root;*trav!=NULL;trav=next)
    {
        next=(val>(*trav)->val)?(&(*trav)->R):(&(*trav)->L);
    }
    leaf=createNode();
    leaf->val=val;
    *trav=leaf;
}

// int delete(BST* root,int val)
// {
//     BST *trav,*next,del=NULL;
//     for(trav=root;*trav!=NULL&&(*trav)->val!=val;trav=next)
//     {
//         next=(val>(*trav)->val)?(&(*trav)->R):(&(*trav)->L);
//     }
//     if(*trav!=NULL)
//     {
//         del=*trav;
//     }
//     return del->val;
// }

void preOrder(BST root)
{
    printf("%d ",root->val);
    if(root->L!=NULL)
    {
        preOrder(root->L);
    }
    if(root->R!=NULL)
    {
        preOrder(root->R);
    }
}

void inOrder(BST root)
{
    if(root->L!=NULL)
    {
        inOrder(root->L);
    }
    printf("%d ",root->val);
    if(root->R!=NULL)
    {
        inOrder(root->R);
    }
}

void postOrder(BST root)
{
    if(root->L!=NULL)
    {
        postOrder(root->L);
    }
    if(root->R!=NULL)
    {
        postOrder(root->R);
    }
    printf("%d ",root->val);
}

int min(BST root)
{
    BST *trav;
    for(trav=&root;(*trav)->L!=NULL;trav=&(*trav)->L){}

    return (*trav)->val;
}

int max(BST root)
{
    BST *trav;
    for(trav=&root;(*trav)->R!=NULL;trav=&(*trav)->R){}

    return (*trav)->val;
}
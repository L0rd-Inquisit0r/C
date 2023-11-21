#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 10

typedef struct node
{
    char elem;
    struct node *link;
}*NODE;

typedef struct dictionary
{
    NODE nodes[SIZE];
}DICT;

int hash(int elem);
void initDict(DICT *D);
void insert(DICT *D,char elem);
void delete(DICT *D,char elem);
bool search(DICT D,char elem);
void display(DICT D,int key);

int main()
{
    DICT D;
    initDict(&D);

    insert(&D,'A');
    insert(&D,'K');
    display(D,1);
    display(D,5);
    delete(&D,'K');
    display(D,5);

    return 0;
}

int hash(int elem)
{
    return elem%SIZE;
}

void initDict(DICT *D)
{
    int n;
    for(n=0;n<SIZE;n++)
    {
        D->nodes[n]=NULL;
    }
}

void insert(DICT *D,char elem)
{
    int n=hash(elem);
    NODE node=(NODE)malloc(sizeof(struct node));
    NODE *trav;

    node->link=NULL;
    node->elem=elem;

    if(D->nodes[n]==NULL)
    {
        D->nodes[n]=node;
    }else
    {   
        for(trav=&(D->nodes[n]);(*trav)->link!=NULL;trav=&(*trav)->link){}
        (*trav)->link=node;
    }
}

void delete(DICT *D,char elem)
{
    int n=hash(elem);
    NODE *trav,prev,del;

    if(D->nodes[n]!=NULL)
    {
        for(trav=&(D->nodes[n]);(*trav)->link!=NULL&&(*trav)->elem!=elem;trav=&(*trav)->link){}
        if((*trav)->elem==elem)
        {
            del=(*trav);
            if((*trav)->link!=NULL)
            {
                *trav=(*trav)->link;
            }else
            {
                *trav=NULL;
            }
            free(del);
            trav=NULL;
        }
    }
}

bool search(DICT D,char elem)
{
    bool ret;
    NODE trav;
    int n=hash(elem);

    for(trav=D.nodes[n];trav!=NULL&&trav->elem!=elem;trav=trav->link)
    ret=(trav!=NULL)?true:false;

    return ret;
}

void display(DICT D,int key)
{
    NODE trav;
    if(D.nodes[key]!=NULL)
    {
        for(trav=D.nodes[key];trav!=NULL;trav=trav->link)
        {
            printf("%c ",trav->elem);
        }
        printf("\n");
    }else
    {
        printf("EMPTY\n");
    }
}
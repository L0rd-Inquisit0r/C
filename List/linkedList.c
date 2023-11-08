#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node *link;
}*LIST,NODE;

LIST createNode();
void initList(LIST* head);
void nullList(LIST* head);
void insFirst(LIST* head,char elem);
void insLast(LIST* head,char elem);
void insert(LIST* head,char elem,int ndx);
void delFirst(LIST* head);
void delLast(LIST* head);
void delete(LIST* head,int ndx);
void display(LIST head);

void main()
{
    LIST head;

    initList(&head);

    insLast(&head,'F');
    insLast(&head,'U');
    insLast(&head,'C');
    insLast(&head,'K');

    delete(&head,4);

    display(head);

    nullList(&head);
}

void initList(LIST* head)
{
    *head=NULL;
}

void nullList(LIST* head)
{
    for(;(*head)!=NULL;delFirst(head)){}
}

LIST createNode()
{
    LIST node=(LIST)malloc(sizeof(NODE));
    node->link=NULL;
    return node;
}

void insFirst(LIST* head,char elem)
{
    LIST node=createNode();
    node->data=elem;
    node->link=*head;
    *head=node;
}

void insLast(LIST* head,char elem)
{
    LIST *trav, node=createNode();
    node->data=elem;
    if(*head!=NULL)
    {
        for(trav=head;(*trav)->link!=NULL;trav=&(*trav)->link){}
        (*trav)->link=node;
    }else
    {
        *head=node;
    }
}

void insert(LIST* head,char elem,int ndx){
    LIST *trav,node=createNode();
    int ctr;
    node->data=elem;
    if(*head!=NULL||ndx!=0)
    {
        for(trav=head,ctr=0;(*trav)->link!=NULL&&ctr<ndx;trav=&(*trav)->link,ctr++){}
        if((*trav)->link!=NULL)
        {
            node->link=(*trav)->link;
        }
        (*trav)->link=node;
    }else
    {
        node->link=*head;
        *head=node;
    }
}

void delFirst(LIST* head)
{
    LIST del;
    if(*head!=NULL)
    {
        del=*head;
        *head=(*head)->link;
        free(del);
    }
}

void delLast(LIST* head)
{
    LIST *trav;
    if(*head!=NULL)
    {
        for(trav=head;(*trav)->link!=NULL;trav=&(*trav)->link){}
        free(*trav);
        *trav=NULL;
    }
}

void delete(LIST* head,int ndx)
{
    LIST *trav,del;
    int ctr;
    if(*head!=NULL)
    {
        for(trav=head,ctr=0;(*trav)->link!=NULL&&ctr<ndx;trav=&(*trav)->link,ctr++){}
        del=(*trav);
        if((*trav)->link!=NULL)
        {
            (*trav)=(*trav)->link;
        }else
        {
            (*trav)=NULL;
        }
        free(del);
    }
}

void display(LIST head)
{
    LIST trav;
    for(trav=head;trav!=NULL;trav=trav->link)
    {
        printf("%c",trav->data);
        if(trav->link!=NULL)
        {
            printf("-->");
        }
    }
}
#include<stdio.h>
#define MAX 5
#define null -1

typedef int CURSOR;

typedef struct node
{
    char data;
    CURSOR link;
}NODE;

typedef struct heap
{
    NODE elem[MAX];
    CURSOR avail;
}HEAP;

CURSOR alloc(HEAP* H);
void dealloc(HEAP* H, CURSOR del);
void initHeap(HEAP* H);

void initList(CURSOR* head);
void nullList(HEAP* H, CURSOR* head);
void insFirst(HEAP* H,CURSOR* head,char elem);
void insLast(HEAP* H,CURSOR* head,char elem);
void insert(HEAP* H,CURSOR* head,char elem,int ndx);
void delFirst(HEAP* H,CURSOR* head);
void delLast(HEAP* H,CURSOR* head);
void delete(HEAP* H,CURSOR* head,int ndx);
void display(HEAP H, CURSOR head);

int main ()
{
    HEAP H;
    CURSOR head;
    initHeap(&H);

    initList(&head);

    insert(&H,&head,'F',1);
    insert(&H,&head,'U',1);
    insert(&H,&head,'C',3);
    insert(&H,&head,'K',2);

    delete(&H,&head,2);

    display(H,head);

    nullList(&H,&head);

    return 0;   
}

CURSOR alloc(HEAP* H)
{
    CURSOR ret=H->avail;
    H->avail=H->elem[ret].link;
    H->elem[ret].link=null;
    return ret;
}

void dealloc(HEAP* H, CURSOR del)
{
    H->elem[del].link=H->avail;
    H->avail=del;
}

void initHeap(HEAP* H)
{
    int ndx=MAX-1;
    H->avail=ndx;
    for(;ndx>=0;ndx--)
    {
        H->elem[ndx].link=ndx-1;
    }
}

void initList(CURSOR* head)
{
    *head=null;
}

void nullList(HEAP* H,CURSOR* head)
{
    for(;*head!=null;delFirst(H,head));
}

void insFirst(HEAP* H,CURSOR* head, char elem)
{
    CURSOR ndx=alloc(H);
    H->elem[ndx].data=elem;
    H->elem[ndx].link=*head;
    *head=ndx;
}

void insLast(HEAP* H,CURSOR* head, char elem)
{
    CURSOR ndx=alloc(H);
    CURSOR trav;
    H->elem[ndx].data=elem;
    if(*head==null)
    {
        *head=ndx;
    }else
    {
        for(trav=*head;H->elem[trav].link!=null;trav=H->elem[trav].link){}
        H->elem[trav].link=ndx;
    }
}

void insert(HEAP* H,CURSOR* head,char elem,int ndx)
{
    CURSOR trav,node=alloc(H);
    int ctr;
    H->elem[node].data=elem;
    if(*head!=null||ndx!=0)
    {
        for(trav=*head,ctr=0;H->elem[trav].link!=null&&ctr<ndx;trav=H->elem[trav].link){}
        if(H->elem[trav].link!=null)
        {
            H->elem[node].link=H->elem[trav].link;
        }
        H->elem[trav].link=node;
    }else
    {
        H->elem[node].link=*head;
        *head=node;
    }
}

void delFirst(HEAP* H,CURSOR* head)
{
    CURSOR del;
    if(*head!=null)
    {
        del=*head;
        *head=H->elem[*head].link;
        dealloc(H,del);
    }
}

void delLast(HEAP *H,CURSOR* head)
{
    CURSOR trav;
    if(*head!=null)
    {
        for(trav=*head;H->elem[trav].link!=null;trav=H->elem[trav].link){}
        dealloc(H,H->elem[trav].link);
        H->elem[trav].link;       
    }
}

void delete(HEAP *H,CURSOR* head,int ndx)
{
    CURSOR trav,prev,del;
    int ctr;
    if(*head!=null)
    {
        for(trav=*head,ctr=0;H->elem[H->elem[trav].link].link!=null&&ctr<ndx;prev=trav,trav=H->elem[trav].link,ctr++){}
        del=trav;
        if(H->elem[trav].link!=null)
        {
            H->elem[prev].link=H->elem[trav].link;
        }else
        {
            H->elem[prev].link=null;
        }
        dealloc(H,del);
    }
}

void display(HEAP H,CURSOR head)
{
    CURSOR trav;
    for(trav=head;trav!=null;trav=H.elem[trav].link)
    {
        printf("%c|%d",H.elem[trav].data,H.elem[trav].link);
        if(H.elem[trav].link!=null)
        {
            printf("-->");
        }
    }
}
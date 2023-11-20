#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 5

typedef struct
{
    char *elem;
    int count;
}LIST;

void initArr(LIST* L);
void insFirst(LIST* L,char elem);
void insLast(LIST* L,char elem);
void insert(LIST* L,char elem,int ndx);
void delFirst(LIST* L);
void delLast(LIST* L);
void delete(LIST* L,int ndx);
void display(LIST L);
char getElem(LIST L,int ndx);
bool isFull(LIST L);
bool isEmpty(LIST L);

void main()
{
    LIST array;

    initArr(&array);
    
    insLast(&array,'K');
    insFirst(&array,'U');
    insert(&array,'C',1);
    insFirst(&array,'F');

    display(array);
    delete(&array,2);

    display(array);
}

void initArr(LIST* L)
{
    L->count=0;
}

void insFirst(LIST* L,char elem)
{
    if(!isFull(*L))
    {
        memmove(&(L->elem[1]),&(L->elem[0]),sizeof(char)*L->count);
        L->elem[0]=elem;
        L->count++;
        printf("INSERTED ELEMENT: %c\n",getElem(*L,0));
    }else
    {
        printf("ERROR: LIST IS FULL\n");
    }
}

void insLast(LIST* L,char elem)
{
    if(!isFull(*L))
    {
        L->elem[L->count++]=elem;
        printf("INSERTED ELEMENT: %c\n",getElem(*L,L->count-1));
    }else
    {
        printf("ERROR: LIST IS FULL\n");
    }
}

void insert(LIST* L,char elem,int ndx){
    if(!isFull(*L))
    {
        if(ndx>=0&&ndx<=L->count)
        {
            memmove(&(L->elem[ndx+1]),&(L->elem[ndx]),sizeof(char)*(L->count-ndx));
            L->elem[ndx]=elem;
            L->count++;
            printf("INSERTED ELEMENT: %c\n",getElem(*L,ndx));
        }else
        {
            printf("ERROR: INDEX NOT WITHIN ARRAY\n");
        }
    }else
    {
        printf("ERROR: LIST IS FULL\n");
    }
}

void delFirst(LIST* L)
{
    if(!isEmpty(*L))
    {
        printf("DELETED ELEMENT: %c\n",getElem(*L,0));
        memmove(&(L->elem[0]),&(L->elem[1]),sizeof(char)*L->count);
        L->count--;
    }else
    {
        printf("ERROR: LIST IS EMPTY\n");
    }
}

void delLast(LIST* L)
{
    if(!isEmpty(*L))
    {
        printf("DELETED ELEMENT: %c\n",getElem(*L,L->count--));
    }else
    {
        printf("ERROR: LIST IS EMPTY\n");
    }
}

void delete(LIST* L,int ndx)
{
    if(!isEmpty(*L))
    {
        if(ndx>=0&&ndx<=L->count)
        {
            printf("DELETED ELEMENT: %c\n",getElem(*L,ndx));
            memmove(&(L->elem[ndx]),&(L->elem[ndx+1]),sizeof(char)*(L->count-ndx));
            L->count--;
        }else
        {
            printf("ERROR: INDEX NOT WITHIN ARRAY\n");
        }
    }else
    {
        printf("ERROR: LIST IS EMPTY\n");
    }
}

void display(LIST L)
{
    int ndx;
    if(!isEmpty(L))
    {
        for(ndx=0;ndx<L.count;ndx++)
        {
            printf("%d. %c\n",ndx,getElem(L,ndx));
        }
    }else
    {
        printf("LIST IS EMPTY\n");
    }
}

char getElem(LIST L,int ndx)
{
    return L.elem[ndx];
}

bool isEmpty(LIST L)
{
    return (L.count==0)?true:false;
}

bool isFull(LIST L)
{
    return (L.count==MAX)?true:false;
}
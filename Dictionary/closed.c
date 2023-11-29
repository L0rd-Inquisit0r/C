#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 10
#define EMPTY 0
#define DELETED -1

typedef char *DICT;

int hash(int elem);
DICT initDict();
void insert(DICT *D,char elem);
void delete(DICT *D,char elem);
bool search(DICT D,char elem);
void display(DICT D,char elem);

int main()
{
    DICT D=initDict();

    insert(&D,'A');
    delete(&D,'A');
    insert(&D,'K');
    insert(&D,'A');

    return 0;
}

int hash(int elem)
{
    return elem%SIZE;
}

DICT initDict()
{
    DICT D;
    int n,size=SIZE*1.25;

    if((D=(DICT)malloc(sizeof(char)*size)))
    {
        for(n=0;n<size;n++)
        {
            D[n]=EMPTY;
        }
    }

    return D;
}

void insert(DICT *D,char elem)
{
    int ctr,size,n;
    for(n=hash(elem),ctr=0,size=SIZE*1.25;ctr<size&&(*D)[n]!=EMPTY&&(*D)[n]!=DELETED;n=(n+1)%size,ctr++);
    if(((*D)[n]==EMPTY)||((*D)[n]==DELETED))
    {
        (*D)[n]=elem;
    }
}

void delete(DICT *D,char elem)
{
    int ctr,size,n;
    for(n=hash(elem),ctr=0,size=SIZE*1.25;ctr<size&&(*D)[n]!=elem;n=(n+1)%size,ctr++);
    if((*D)[n]==elem)
    {
        (*D)[n]=DELETED;
    }
}

bool search(DICT D,char elem)
{
    int ctr,size,n;
    bool ret;
    for(n=hash(elem),ctr=0,size=SIZE*1.25;ctr<size&&D[n]!=elem;n=(n+1)%size,ctr++);
    ret=(D[n]==elem)?true:false;
    
    return ret;
}

void display(DICT D,char elem)
{

}
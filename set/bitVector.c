#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef int SET[size];

void initSet(SET* set);
void insert(SET* set,int ndx);
void delete(SET* set,int ndx);
void display(SET set);
SET* onion(SET A,SET B);
SET* intersection(SET A,SET B);
SET* difference(SET A,SET B);

int main()
{
    SET A={1,1,1,1,1,0,0,0,0,0};
    SET B={0,1,0,1,0,1,0,1,0,1};
    SET *U;
    display(A);
    display(B);

    U=onion(A,B);

    return 0;
}

void initSet(SET* set)
{
    int ndx;
    for(ndx=0;ndx<size;ndx++)
    {
        (*set)[ndx]=0;
    }
}

void insert(SET *set,int ndx)
{
    (*set)[ndx]=1;
}

void delete(SET *set,int ndx)
{
    (*set)[ndx]=0;
}

void display(SET set)
{
    int ndx;
    for(ndx=0;ndx<size;ndx++)
    {
        printf("%d ",set[ndx]);
    }
    printf("\n");
}

SET* onion(SET A,SET B)
{
    SET* set=(SET*)malloc(sizeof(SET));
    int ndx;
    initSet(set);

    for(ndx=0;ndx<size;ndx++)
    {
        if(A[ndx]==1||B[ndx]==1)
        {
            (*set)[ndx]=1;
        }
    }

    return set;
}

SET* intersection(SET A,SET B)
{
    SET* set=(SET*)malloc(sizeof(SET));
    int ndx;
    initSet(set);

    for(ndx=0;ndx<size;ndx++)
    {
        if(A[ndx]==1&&B[ndx]==1)
        {
            (*set)[ndx]=1;
        }
    }

    return set;
}

SET* difference(SET A,SET B)
{
    SET* set=(SET*)malloc(sizeof(SET));
    int ndx;
    initSet(set);

    for(ndx=0;ndx<size;ndx++)
    {
        if(A[ndx]==1&&A[ndx]!=B[ndx])
        {
            (*set)[ndx]=1;
        }
    }

    return set;
}
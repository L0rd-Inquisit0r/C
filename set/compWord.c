#include<stdio.h>

typedef unsigned char SET;

SET initSet();
void insert(SET *set,int ndx);
void delete(SET *set,int ndx);
void display(SET set);
SET onion(SET A,SET B);
SET intersection(SET A,SET B);
SET difference(SET A,SET B);

int main()
{
    SET set=240;

    display(set);

    display(onion(69,42));
    display(intersection(69,42));
    display(difference(69,42));

    return 0;
}

SET initSet()
{
    return 0;
}

void insert(SET *set,int ndx)
{
    SET n=0<<ndx;
    *set|=n;
}

void delete(SET *set,int ndx)
{
    SET n=0<<ndx;
    *set&=~n;
}

void display(SET set)
{
    SET ndx=1;
    for(ndx<<=sizeof(SET)*8-1;ndx!=0;ndx>>=1)
    {
        printf("%d",(set&ndx)?1:0);
    }
    printf("\n");
}

SET onion(SET A,SET B)
{
    return A|B;
}

SET intersection(SET A,SET B)
{
    return A&B;
}

SET difference(SET A,SET B)
{
    return A&~B;
}
#include<stdio.h>
#define MAX 5
#define null -1

typedef int STACK;

typedef struct node
{
    char data;
    STACK link;
}NODE;

typedef struct heap
{
    NODE elem[MAX];
    STACK avail;
}HEAP;

STACK alloc(HEAP* H);
void dealloc(HEAP* H, STACK del);
void initHeap(HEAP* H);

void initStack(STACK* S);
void push(HEAP* H,STACK* S,char elem);
void pop(HEAP* H,STACK* S);
char top(HEAP H,STACK S);

int main()
{
    HEAP H;
    STACK S;
    initHeap(&H);
    initStack(&S);
    
    push(&H,&S,'K');
    push(&H,&S,'C');
    push(&H,&S,'U');
    push(&H,&S,'F');

    printf("Top element in stack: %c\n",top(H,S));
    pop(&H,&S);
    printf("Top element in stack: %c\n",top(H,S));

    return 0;
}

STACK alloc(HEAP* H)
{
    STACK ret=H->avail;
    H->avail=H->elem[ret].link;
    H->elem[ret].link=null;
    return ret;
}

void dealloc(HEAP* H,STACK del)
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

void initStack(STACK* S)
{
    *S=null;
}

void push(HEAP* H,STACK* S, char elem)
{
    STACK ndx=alloc(H);
    H->elem[ndx].data=elem;
    H->elem[ndx].link=*S;
    *S=ndx;
}

void pop(HEAP* H,STACK* S)
{
    STACK del;
    if(*S!=null)
    {
        del=*S;
        *S=H->elem[*S].link;
        dealloc(H,del);
    }
}

char top(HEAP H,STACK S)
{
    return H.elem[S].data;
}
#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct
{
    char data[MAX];
    int top;
}STACK;

void initStack(STACK* S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void push(STACK* S,char elem);
void pop(STACK* S);
char top(STACK S);

int main()
{
    STACK S;
    initStack(&S);

    push(&S,'K');
    push(&S,'C');
    push(&S,'U');
    push(&S,'F');

    printf("Top element of stack: %c\n",top(S));
    pop(&S);
    printf("Top element of stack: %c\n",top(S));

    return 0;
}

void initStack(STACK* S)
{
    S->top=-1;
}

bool isEmpty(STACK S)
{
    return (S.top==-1)?true:false;
}

bool isFull(STACK S)
{
    return (S.top==MAX-1)?true:false;
}

void push(STACK* S,char elem)
{
    if(!(isFull(*S)))
    {
        S->data[++S->top]=elem;
    }
}

void pop(STACK* S)
{
    if(!(isEmpty(*S)))
    {
        S->top--;
    }
}

char top(STACK S)
{
    return S.data[S.top];
}
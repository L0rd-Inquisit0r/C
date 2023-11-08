#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct
{
    char *data;
    int top;
}*STACK,ARRAY;

STACK initStack();
void nullStack(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void push(STACK S,char elem);
void pop(STACK S);
char top(STACK S);

int main()
{
    STACK S;
    S=initStack();

    push(S,'K');
    push(S,'C');
    push(S,'U');
    push(S,'F');

    printf("Top element of stack: %c\n",top(S));
    pop(S);
    printf("Top element of stack: %c\n",top(S));

    nullStack(S);
    return 0;
}

STACK initStack()
{
    STACK S;
    S=(STACK)malloc(sizeof(ARRAY));
    S->data=(char*)malloc(sizeof(char)*MAX);
    S->top=-1;
    return S;
}

void nullStack(STACK S)
{
    free(S->data);
    free(S);
}

bool isEmpty(STACK S)
{
    return (S->top==-1)?true:false;
}

bool isFull(STACK S)
{
    return (S->top==MAX-1)?true:false;
}

void push(STACK S,char elem)
{
    if(!(isFull(S)))
    {
        S->data[++S->top]=elem;
    }
}

void pop(STACK S)
{
    if(!(isEmpty(S)))
    {
        S->top--;
    }
}

char top(STACK S)
{
    return S->data[S->top];
}
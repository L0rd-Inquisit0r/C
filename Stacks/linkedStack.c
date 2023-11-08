#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    char data;
    struct node *link;
}*STACK;

STACK createNode();
void initStack(STACK* S);
void nullStack(STACK* S);
bool isEmpty(STACK* S);
void push(STACK* S,char elem);
void pop(STACK* S);
char top(STACK* S);

int main()
{
    STACK S;
    initStack(&S);
    
    push(&S,'K');
    push(&S,'C');
    push(&S,'U');
    push(&S,'F');

    printf("Top element in stack: %c\n",top(&S));
    pop(&S);
    printf("Top element in stack: %c\n",top(&S));

    nullStack(&S);
    return 0;
}

STACK createNode()
{
    STACK S=(STACK)malloc(sizeof(struct node));
    S->link=NULL;
    return S;
}

void initStack(STACK* S)
{
    *S=NULL;
}

void nullStack(STACK* S)
{
    for(;!isEmpty(S);pop(S)){}
}

bool isEmpty(STACK* S)
{
    return(*S==NULL)?true:false;
}

void push(STACK* S,char elem)
{
    STACK node=createNode();
    node->data=elem;
    node->link=*S;
    *S=node;
}

void pop(STACK* S)
{
    STACK del;
    if(!(isEmpty(S)))
    {
        del=*S;
        *S=(*S)->link;
        free(del);
    }
}

char top(STACK* S)
{
    return (*S)->data; 
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    char data;
    struct node *link;
}*NODE;

typedef struct queue
{
    NODE first;
    NODE last;
}QUEUE;

NODE createNode();
void initQueue(QUEUE* Q);
void nullQueue(QUEUE* Q);
bool isEmpty(QUEUE* Q);
void enqueue(QUEUE* Q,char elem);
void dequeue(QUEUE* Q);
char front(QUEUE* Q);

int main()
{
    QUEUE Q;
    initQueue(&Q);

    enqueue(&Q,'K');
    enqueue(&Q,'C');
    enqueue(&Q,'U');
    enqueue(&Q,'F');

    printf("Front Element is: %c\n",front(&Q));
    dequeue(&Q);
    printf("Front Element is: %c\n",front(&Q));

    nullQueue(&Q);
    return 0;
}

NODE createNode()
{
    NODE node=(NODE)malloc(sizeof(struct node));
    node->link=NULL;
    return node;
}

void initQueue(QUEUE* Q)
{
    Q->first=NULL;
    Q->last=NULL;
}

void nullQueue(QUEUE* Q)
{
    for(;!isEmpty(Q);dequeue(Q)){}
}

bool isEmpty(QUEUE* Q)
{
    return(Q->first==NULL&&Q->first==Q->last)?true:false;
}

void enqueue(QUEUE* Q,char elem)
{
    NODE node=createNode();
    node->data=elem;
    if(!isEmpty(Q))
    {
        Q->last->link=node;
        Q->last=Q->last->link;
    }else
    {
        Q->first=node;
        Q->last=Q->first;
    }
}

void dequeue(QUEUE* Q)
{
    NODE del;
    if(!isEmpty(Q))
    {
        del=Q->first;
        Q->first=Q->first->link;
        free(del);
        if(Q->first==NULL)
        {
            Q->last=NULL;
        }
    }
}

char front(QUEUE* Q)
{
    return Q->first->data;
}
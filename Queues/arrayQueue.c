#include<stdio.h>
#include<stdbool.h>
#define MAX 8

typedef struct
{
    char data[MAX];
    int front;
    int rear;
}QUEUE;

void initQueue(QUEUE* Q);
bool isEmpty(QUEUE Q);
bool isFull(QUEUE Q);
void enqueue(QUEUE* Q,char elem);
void dequeue(QUEUE* Q);
char front(QUEUE Q);

int main()
{
    QUEUE Q;
    initQueue(&Q);

    enqueue(&Q,'F');
    enqueue(&Q,'U');
    enqueue(&Q,'C');
    enqueue(&Q,'K');

    printf("Front Element is: %c\n",front(Q));
    dequeue(&Q);
    printf("Front Element is: %c\n",front(Q));

    return 0;
}

void initQueue(QUEUE* Q)
{
    Q->rear=0;
    Q->front=1;
}

bool isEmpty(QUEUE Q)
{
    return(Q.front==(Q.rear+1)%MAX)?true:false;
}

bool isFull(QUEUE Q)
{
    return(Q.front==(Q.rear+2)%MAX)?true:false;
}

void enqueue(QUEUE *Q,char elem)
{
    if(!(isFull(*Q)))
    {
        Q->rear=(Q->rear+1)%(MAX);
        Q->data[Q->rear]=elem;
    }
}

void dequeue(QUEUE *Q)
{
    if(!(isEmpty(*Q)))
    {
        Q->front=(Q->front+1)%(MAX);
    }
}

char front(QUEUE Q)
{
    return Q.data[Q.front];
}
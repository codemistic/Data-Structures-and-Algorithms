#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int itemType;

typedef struct Queue
{
    int front, rear, count;
    itemType a[MAX];
}Queue;

void initialize(Queue *q);
int full(Queue *q);
int empty(Queue *q);
void addition(Queue *q, itemType x);
itemType deletion(Queue *q);
int size(Queue *q);

int main()
{
    itemType x;
    Queue q;

    initialize(&q);

    x = 10; addition(&q, x);
    x = 50; addition(&q, x);
    x = 30; addition(&q, x);
    x = 60; addition(&q, x);
    x = 90; addition(&q, x);
    //x = 20; addition(&q, x);

    while(!empty(&q))
        printf("Deleted item is: %d\n", deletion(&q));

    x = deletion(&q);

    return 0;
}

void initialize(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int full(Queue *q)
{return q->count==MAX;}
int empty(Queue *q)
{return q->count==0;}

void addition(Queue *q, itemType x)
{
    if (full(q))
    {
        printf("Queue overflow\n");
        exit(1);
    }
    ++q->count;
    q->rear = (q->rear==MAX-1)?0:q->rear+1;
    q->a[q->rear] = x;
}

itemType deletion(Queue *q)
{
    itemType x;
    if (empty(q))
    {
        printf("Queue underflow\n");
        exit(2);
    }
    --q->count;
    x = q->a[q->front];
    q->front = (q->front+1)%MAX;
    return x;
}

int size(Queue *q)
{return q->count;}

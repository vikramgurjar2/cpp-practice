#include <iostream>
#include <stdio.h>
using namespace std;
struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct circularqueue *q)
{
    if ((q->r+1)%q->size==q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct circularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct circularqueue *q, int val)
{

    if (isFull(q))
    {
        printf("the circularqueue is full");
    }
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}
int  denqueue(struct circularqueue *q)
{
int a=-1;

    if (isEmpty(q))
    {
        printf("the queue is empty ");
    }
    else
    {
    q->f=(q->f+1)%q->size;
    a= q->arr[q->f];
    }
return a;
}

int main()
{
    struct circularqueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int)); 
    enqueue(&q,33);
    enqueue(&q,83);
    enqueue(&q,53);
    enqueue(&q,53);
    printf("dequeuing element %d\n",denqueue(&q));
    printf("dequeuing element %d\n",denqueue(&q));
    printf("dequeuing element %d\n",denqueue(&q));
printf("dequeuing element %d\n",denqueue(&q));
printf("dequeuing element %d\n",denqueue(&q));
    enqueue(&q,33);
    
return 0;}
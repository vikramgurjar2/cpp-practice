#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node *f = NULL;
struct Node *r = NULL;
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL)
    {
        printf("queue is full");
    }
    else
    {
        n->next = NULL;
        n->data = val;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val = -1;

    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("the queue is empty ");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    struct Node *f = NULL;
    struct Node *r = NULL;
    enqueue(45);
    enqueue(45);
    enqueue(45);
    enqueue(45);
    linkedListTraversal(f);
    return 0;
}
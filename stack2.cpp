#include <iostream>
#include <stdio.h>
using namespace std;
struct stack
{
    int *arr;
    int size;
    int top;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("the stack is full/n ");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("the stack has been created sucessfully");
    printf("%d\n", isFull(sp));
    printf("%d\n", isEmpty(sp));
    push(sp, 9);
    push(sp, 59);
    push(sp, 59);
    push(sp, 59);
    push(sp, 59);
    push(sp, 59);
    push(sp, 59);
    push(sp, 59);
    push(sp, 59);
    push(sp, 59);
    push(sp, 59);
    printf("%d\n", isFull(sp));
    printf("%d\n", isEmpty);

    return 0;
}
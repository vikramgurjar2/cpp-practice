#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
int linklisttraversior(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
};
struct Node *incertionatfirst(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *incertioninbetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node  *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;

    p->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // alloting memory for the list in heap .

    head = (struct Node *)malloc(sizeof(struct Node));

    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 56;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 24;
    third->next = fourth;

    fourth->data = 45;
    fourth->next = NULL;
    linklisttraversior(head);
    incertioninbetween(head, 67, 3);
    printf("after incertion  in between \n");

    linklisttraversior(head);

    return 0;
}
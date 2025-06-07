#include <iostream>
using namespace std;

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
struct Node *deletefirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node *deleteinbetween(struct Node *head, int index)
{

    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}
struct Node *deleteatlast(struct Node *head)
{

    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
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
    // head = deletefirst(head);

    cout << "\n";
   // deleteinbetween(head, 1);

   // linklisttraversior(head);
    cout << "\n";
deleteatlast(head);
     linklisttraversior(head);
    return 0;
}
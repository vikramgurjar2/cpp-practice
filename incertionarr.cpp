#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void printlist(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            /* code */ cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}
//struct Node *incertionatfirst(struct Node *head, int data)
//{
//    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//    ptr->data = data;
//    ptr->next = head;
//    return ptr;
//}

struct Node *incertionatfirst(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = head;
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 11;
    head->next = first;
    first->data = 22;
    first->next = second;
    second->data = 33;
    second->next = third;
    third->data = 44;
    third->next = fourth;
    fourth->data = 55;
    fourth->next = NULL;
    printlist(head);
   // printlist(head);
    incertionatfirst(head, 69);
    printlist(head);
    return 0;
}

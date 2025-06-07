#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node* top = NULL;

void printlist(Node *head)
{
    Node *ptr = head;
    if (head != NULL)
    {
        do
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        } while (ptr != head);
    }
}

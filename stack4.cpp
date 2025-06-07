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
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node* push(struct Node* top ,int x)
{
    if(isFull(top)){
        cout<<"the stack is overflow "<<endl;
    }
    else{
        struct Node* n = (struct Node*)malloc(sizeof(struct Node) );
        n->data=x;
        n->next = top;
        top =n;
        return top;

    }
}
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//void pop(){
//
//    if(top==NULL){
//        printf("the stack is already fill ");
//    }
//    else{
//
//        struct Node* n= top;
//        n->next= top;
//        free(n);
//       
//    }
//}
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
//int peek(int pos){
//    struct Node* ptr = top;
//    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
//        ptr= ptr->next;
//    }
//    if(ptr!=NULL){
//        return ptr->data;
//    }
//    else{
//        return -1;
//    }
//}
int peek(int pos){
    struct Node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int main()
{
    struct Node *top = NULL;
 top = push(top,67);
 top = push(top,7);
 top = push(top,16);
 top = push(top,61);
 
 //pop(top);
 //int element = pop(&top);
//-+*****
// printlist(top);
 
  for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(i));
    }
    return 0;
}
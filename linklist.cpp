#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

//int linklisttraversor(struct Node *ptr)
//{
//   
//    do{
//        printf("Element : %d\n", ptr->data);
//        ptr = ptr->next;
//    }while (ptr != head);
//
//};

void printList(Node *head) 
{ 
    Node *temp = head; 
    if (head != NULL) 
    { 
        do
        { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
        while (temp != head); 
    } 
} 
int incertion(struct Node *head,int data,int index ){
struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
struct Node *p = head ;
int i=0;
while (i != index-1)
{
    /* code */
}






}





int main(){
struct Node *head; 
struct Node *first ;

struct Node *second ;
struct Node *third ;
struct Node *fourth ;
head =(struct Node *)malloc(sizeof(struct Node ));
first  =(struct Node *)malloc(sizeof(struct Node) );
second  =(struct Node *)malloc(sizeof(struct Node) );
third  = (struct Node *)malloc(sizeof(struct Node) );
fourth  = (struct Node *)malloc(sizeof(struct Node) );
head->data=44;
head->next =first;
first->data=67;
first->next=second ;
second->data=88;
second->next=third;
third->data=34;
third->next=fourth;
fourth->data=78;
fourth->next= head;
//linklisttraversor(head  );
printList(head)
;
return 0;

}

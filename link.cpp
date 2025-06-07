#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next ;
    
};


void push(Node** head,int n){
    Node* first = new Node();
    first->data=n;
    first->next= *head;
    *head =first;
}








//void endincertion(Node** head_ref ,int data){
//    
//    Node* temp = new Node() ;
//    Node *last = *head_ref;
//    while(last->next!=NULL){
//        last=last->next ;
//    }
//    temp->data=data;
//    temp->next=NULL ;
//    last->next=temp;
//}
//void deletion(Node** head_ref ,int index){
//   // *head_ref=*head;
//    Node  *p =*head_ref;
//    Node *q =p->next;
//    
//   for(int i=0;i<index-1;i++){
//       p++;
//       q++;
//       
//   }
//   p->next=q->next;
//   free(q);
//    
//}
Node* reversefunction(Node* head){
Node* prev =NULL ;
Node* curr =head;
Node* forward=NULL;

while(curr!=NULL){
 forward=curr->next;

curr->next=prev;
prev=curr;
curr=forward;


}


 return prev;


}
void printlist(Node *temp){
   
    while(temp!=NULL){
        cout<<""<<" "<<temp->data ;
        temp=temp->next ;
    }
    cout<<endl;
}
    

int main() {
	//code
	
struct Node* head = NULL;
   push(&head, 1);
   push(&head, 2);
   push(&head, 3);
   push(&head, 4);
   push(&head, 5);
printlist(head);	
reversefunction(head);	
//push(&head,98);
printlist(head);
////incertion(head,99);
//
//endincertion(&head,70);
//deletion(&head,4);
//printlist(head);
//
//printlist(head);
//
////printlist(head);
//
//
//
	return 0;
}
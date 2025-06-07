
                




 

#include <bits/stdc++.h>
using namespace std;
  
class Node {
public:
    int data;
    Node* next;
};
  
// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}
  
// Driver's code
int main()
{
    // head ;
    // second;
    // third ;
  
    // allocate 3 nodes in the heap
   Node* head = new Node();
   Node* second = new Node();
   Node* third = new Node();
  
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second
  
    second->data = 2; // assign data to second node
    second->next = third;
  
    third->data = 3; // assign data to third node
    third->next = NULL;
  
    // Function call
    printList(head);
  
    return 0;
}


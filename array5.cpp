#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // first i need to find total nodes in linked list
    ListNode *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    int t = count - n;
    if (n > count)
    {
        return head;
    }
    if (count == n)
    {
        return head->next;
    }

    ListNode *ptr = head;
    while (t > 1)
    {
        ptr = ptr->next;
        t--;
    }
    ptr->next = ptr->next->next;
    return head;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 6;
    head = removeNthFromEnd(head, n);
    // Print the modified linked list
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    return 0;
}
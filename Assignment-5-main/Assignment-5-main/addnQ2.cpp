#include <iostream>
#include <vector>
using namespace std;
class node 
{
public:
    int data;
    node *next;
    node(int data1, node *next1) 
    {
        data = data1;
        next = next1;
    }
    node(int data1) {
        data = data1;
        next = nullptr;
    }
};
node *ConvertArr2LL(vector<int> &arr) 
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++) 
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
node *reverseKGroup(node *head, int k) 
{
    node *curr = head;
    int count = 0;
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }
    if (count < k) return head;
    curr = head;
    node *prev = nullptr, *next = nullptr;
    count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next) head->next = reverseKGroup(next, k);
    return prev;
}
void printList(node *head) 
{
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
}
int main() 
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    node *head = ConvertArr2LL(arr);
    cout<<"Original linked list :- "<<endl;
    printList(head);
    int k = 3;
    node *newHead = reverseKGroup(head, k);
    cout<<"Reversed linked list :- "<<endl;
    printList(newHead);
}

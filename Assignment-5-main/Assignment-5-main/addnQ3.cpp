#include <iostream>
#include<vector>
using namespace std;
class node 
{
public:
    int data;
    node* next;
    node(int data1 , node *next1) 
    {
        data = data1;
        next = next1;
    }
    node(int data1) 
    {
        data = data1;
        next = nullptr;
    }
};
void removeLoop(node* head) 
{
    node *slow = head, *fast = head;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (fast == nullptr || fast->next == nullptr) return;

    slow = head;
    if (slow == fast) 
    {
        while(fast->next != slow)
        {
            fast = fast->next;
        }
    }
    else 
    {
        while(slow->next != fast->next) 
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = nullptr;
}
void print(node* head)
{
    node* temp = head;
    while (temp != nullptr ) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main() {
    node* head = new node(1);
    head->next = new node(7);
    head->next->next = new node(3);
    head->next->next->next = new node(6);
    head->next->next->next->next = head->next;
    removeLoop(head);
    cout << "Linked list after removing loop:\n";
    print(head);
    return 0;
}
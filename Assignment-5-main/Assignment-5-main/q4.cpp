#include<iostream>
#include<vector>
using namespace std;
class node 
{
public:
    int data;
    node *next;
    node(int data1, node *next1) {
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
node* reverseLL(node* head) 
{
    node *prev = nullptr;
    node *curr = head;
    node *front = nullptr;
    while (curr != nullptr) 
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev; //new head
}
void print(node *head) 
{
    node *temp = head;
    while (temp) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() 
{
    vector<int> arr = {1,2,3,4,5};
    node *head = ConvertArr2LL(arr);
    cout << "The given linked list is :-" << endl;
    print(head);
    cout<<"The reversed linked list is :-" << endl;
    head = reverseLL(head);
    print(head);
}
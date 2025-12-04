#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node *back;
    node(int data1,node *next1, node *back1)
    {
        data=data1;
        next=next1;
        back=back1;
    }
    node(int data1)
    {
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
node *convertArr2DLL(vector <int> &arr)
{
    node *head = new node(arr[0]);
    node *prev = head;
    for(int i=1;i<arr.size();i++)
    {
        node *temp = new node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
node *deletenode(node *head , int val)
{
    if(head->next == nullptr || head->data==val) //single element DLL or head is to be deleted
    {
        node *newhead = head->next;
        free(head);
        return newhead;
    }
    node *temp=head->next;
    while(temp->next!=nullptr || temp->data!=val)
    {
        temp=temp->next;
    }
    if(temp->next==nullptr) //tail is to be removed
    {
        node *prev = temp->back;
        temp->back = nullptr;
        prev->next = nullptr;
        free(temp);
        return head;
    }
    else
    {
        node *prev = temp->back;
        node *front = temp->next;
        prev->next=front;
        front->back=prev;
        temp->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return head;
    }
}
void print(node *head)
{
    node *temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() 
{
    vector<int> arr = {5,19,4,3};
    node *head = convertArr2DLL(arr);
    int choice, val, ref;
    do {
        cout << "\n<==== MENU ====>\n";
        cout << "1. Delete a specific node\n";
        cout << "2. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter node value to be deleted";
            cin >> val;
            head =deletenode(head, val);
            break;
        case 2:
            print(head);
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}

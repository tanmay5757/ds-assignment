#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node *back;
    node(int data1,node *next1)
    {
        data=data1;
        next=next1;
    }
    node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};
node *convertArr2CLL(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < arr.size(); i++) 
    {
        node *mover = new node(arr[i]);
        temp->next = mover;
        temp = mover;
    }
    temp->next = head;
    return head;
}
void sizeCLL(node *head)
{
    int count = 1;
    node *temp = head;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    cout<<endl<<"Size of CLL is :- "<<count<<endl;
}
void printCLL(node *head) {
    node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    vector<int> arr = {5,17,19,12,10,11,12};
    node *head = convertArr2CLL(arr);
    cout << "The circular linked list is:\n";
    printCLL(head);
    sizeCLL(head);
}

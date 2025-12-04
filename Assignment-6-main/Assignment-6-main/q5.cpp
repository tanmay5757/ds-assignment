#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
    int data;
    node *next;
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
node *convertArr2SLL(vector <int> &arr)
{
    node *head = new node(arr[0]);
    node *temp = head;
    for(int i=1;i<arr.size();i++)
    {
        node *mover = new node(arr[i]);
        temp->next = mover;
        temp = mover;
    }
    return head;
}
node *convertArr2CLL(vector <int> &arr)
{
    node *head = new node(arr[0]);
    node *temp = head;
    for(int i=1;i<arr.size();i++)
    {
        node *mover = new node(arr[i]);
        temp->next = mover;
        temp = mover;
    }
    temp->next = head;
    return head;
}
void CLLchecker(node *head)
{
    node *temp = head;
    while(temp->next!=nullptr && temp->next!=head)
    {
        temp=temp->next;
    }
    if(temp->next==nullptr) cout<<"            a single linked list"<<endl;
    else if(temp->next==head) cout<<"          a circular linked list"<<endl;
}
int main() 
{
    vector<int> arr1 = {2,4,6,7,5};
    vector<int> arr2 = {1,14,9,8,0};
    node *head1 = convertArr2SLL(arr1);
    node *head2 = convertArr2CLL(arr2);
    cout<<"arr 1 is : - "<<endl;
    CLLchecker(head1);
    cout<<"arr 2 is : - "<<endl;
    CLLchecker(head2);
}

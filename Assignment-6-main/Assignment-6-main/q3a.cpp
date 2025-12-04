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
void sizeDLL(node *head)
{
    int count = 1;
    node *temp = head;
    while(temp->next!=nullptr)
    {
        count++;
        temp=temp->next;
    }
    cout<<endl<<"Size of DLL is :- "<<count<<endl;
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
int main() {
    vector<int> arr = {41,67,69,420,21};
    node *head = convertArr2DLL(arr);
    cout << "The double linked list is:\n";
    print(head);
    sizeDLL(head);
}

//rotate node by k steps
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
node *rotatebyKsteps(node *head , int k)
{
    int count = 1;
    node *temp = head;
    while(temp->next!=nullptr)
    {
        if(k==count)
        {
           node *newhead = temp->next; 
           temp->next=nullptr;
           node *mover = newhead;
           while(mover->next!=nullptr)
           {
               mover=mover->next;
           }
           mover->next = head;
           return newhead;
        }
        count++;
        temp = temp->next;
    }
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
    vector<int> arr = {10,20,30,40,50};
    node *head = ConvertArr2LL(arr);
    cout<<"The original linked list is :- "<<endl;
    print(head);
    cout<<endl<<"Enter K :- ";
    int K;
    cin>>K;
    node *newhead = rotatebyKsteps(head,K);
    cout<<"The linked list after rotating K steps is :- "<<endl;
    print(newhead);
}
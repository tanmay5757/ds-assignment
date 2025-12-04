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
void printmiddleofnode(node *head)
{
    node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    int middle = count/2 + 1;
    node *track = head;
    int elno = 0;
    while(track!=NULL)
    {
        elno++;
        if(elno==middle) break;
        track=track->next;
    }
    cout<<"The middle of node is :- "<<track->data<<endl;
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
    printmiddleofnode(head);
}
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
node *occurence(node *head, int key) {
    int count = 0;
    while (head != NULL && head->data == key)  // for cases when key=head
    {
        node *del = head;
        head = head->next;
        free(del);
        count++;
    }
    node *temp = head;
    while (temp!=NULL && temp->next) 
    {
        if(temp->next->data == key) 
        {
            node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
            count++;
        }
        else 
        {
            temp = temp->next;
        }
    }
    cout<<"Key frequency is :- " <<count<<endl;
    return head;
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
int main() {
    vector<int> arr = {1, 2, 1, 2, 1, 3, 1};
    node *head = ConvertArr2LL(arr);
    cout << "The given linked list is :-" << endl;
    print(head);
    head = occurence(head, 1);
    cout << "The non-repeating linked list is :-" << endl;
    print(head);
}

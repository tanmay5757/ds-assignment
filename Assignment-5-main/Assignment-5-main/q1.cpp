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
node *convertArr2LL(vector <int> &arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for(int i=1;i<arr.size();i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
node *inserthead(node *head , int val)
{
    if(head == nullptr) //linked list is empty case
    {
        node *insert = new node(val);
        return insert;
    }
    node *insert = new node(val,head); 
    return insert;
}
node *inserttail(node *head , int val)
{
    node *temp = head;
    while(temp->next != nullptr)
    {
        temp=temp->next;
    }
    node *insert = new node(val);
    temp->next = insert;
    return head;
}
node *insertbeforeVAL(node *head , int put , int bval)
{
    node *temp = head;
    if(temp->data==bval) 
    {
        return inserthead(head,put);
    }
    while(temp->next) 
    {
        temp=temp->next;
        if(temp->next->data==bval) break;
    }
    if(temp->next==nullptr)
    {
        cout<<"The given element not present.\n";
        return head;
    }
    node *insert = new node(put,temp->next);
    temp->next=insert;
    return head;
}
node *insertafterVAL(node *head , int put , int aval)
{
    node *temp = head;
    while(temp->next!=nullptr) 
    {
        if(temp->data==put) break;
        temp=temp->next;
    }
    if(temp->next==nullptr)
    {
        return inserttail(head,put);
    }
    node *insert = new node(put,temp->next);
    temp->next=insert;
    return head;
}
node *deletehead(node *head)
{
    if(head->next==nullptr)
    {
        return nullptr;
    }
    node *newhead=head->next;
    free(head);
    return newhead;
}
node *deletetail(node *head)
{
    node *temp=head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    node *tail=temp->next;   
    temp->next=nullptr;
    free(tail);
    return head;
}
node *deletesval(node *head , int dval)
{
    if(head->data==dval) return deletehead(head); //dval=head
    node *temp=head;
    while(temp->next!=nullptr)
    {
        if(temp->next->data==dval) break;
        temp=temp->next;
    }
    if(temp->next==nullptr)
    {
        cout<<"Node not present"; //dval=not present
        return head;
    }
    node *remove = temp->next;
    temp->next=remove->next;
    remove->next=nullptr;
    free(remove);
    return head;
}
void searchelement(node *head , int val)
{
    node *temp=head;
    int counter=0;
    while(temp)
    {
        if(temp->data==val) break;
        temp =temp->next;
        counter++;
    }
    if(temp->next=nullptr) cout<<"NO such element prsent.\n";
    if(counter==0) cout<<"The given node is head\n";
    else
    cout<<"The node is "<<counter<<" elements from head"<<endl;
}
void printLL(node *head)
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
    vector <int> arr = {1,12,15,17,19}; //17
    node *head = convertArr2LL(arr);
    int choice, val, ref;
    do {
        cout << "\nMENU:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a specific value\n";
        cout << "4. Insert after a specific value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display all nodes\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> val;
            head = inserthead(head, val);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> val;
            head = inserttail(head, val);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter value before which to insert: ";
            cin >> ref;
            head = insertbeforeVAL(head, val, ref);
            break;
        case 4:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter value after which to insert: ";
            cin >> ref;
            head = insertafterVAL(head, val, ref);
            break;
        case 5:
            head = deletehead(head);
            break;
        case 6:
            head = deletetail(head);
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            head = deletesval(head, val);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            searchelement(head, val);
            break;
        case 9:
            cout << "Linked List: ";
            printLL(head);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
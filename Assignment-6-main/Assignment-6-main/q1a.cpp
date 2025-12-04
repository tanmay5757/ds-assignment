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
node *insertfirstnode(node *head , int val)
{
    node *newhead = new node(val , head , nullptr);
    head->back = newhead;
    return newhead;
}
node *insertlastnode(node *head , int val)
{
    node *temp = head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    node *tail=new node(val,nullptr,temp);
    temp->next=tail;
    return head;
}
node *BeforeVAL(node *head , int put , int val)
{
    if(head->next==nullptr || head->data==val) return insertfirstnode(head,put);
    node *temp = head->next;
    while(temp->next!=nullptr || temp->data!=val) //5 19 4 3  
    {
        temp=temp->next;
    }
    if(temp->next==nullptr) cout<<"No such Node present"<<endl; 
    node *prev = temp->back;
    node *insertbefore = new node(put,temp,prev);
    prev->next=insertbefore;
    temp->back=insertbefore;
    return head;
}
node *AfterVAL(node *head , int put , int val)
{
    if(head->next==nullptr) return insertlastnode(head , put);
    node *temp = head;
    while(temp==nullptr || temp->data!=val) //5 19 4 3
    {
        temp=temp->next;
    }
    if(temp==NULL) cout<<"No such node present"<<endl;
    if(temp->next==nullptr) return insertlastnode(head , put);
    node *front = temp->next;
    node *insertafter = new node(val,temp,front);
    front->back=insertafter;
    temp->next=insertafter;
    return head;
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
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> val;
            head = insertfirstnode(head, val);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> val;
            head = insertlastnode(head, val);
            break;

        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter value before which to insert: ";
            cin >> ref;
            head = BeforeVAL(head, val, ref);
            break;

        case 4:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter value after which to insert: ";
            cin >> ref;
            head = AfterVAL(head, val, ref);
            break;

        case 5:
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

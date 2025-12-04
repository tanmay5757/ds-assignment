#include <iostream>
#include <vector>
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
    for (int i = 1; i < arr.size(); i++) {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int getLength(node *head) 
{
    node *temp = head;
    int len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
node *getIntersectionNode(node *headA, node *headB) 
{
    int lenA = getLength(headA), lenB = getLength(headB);
    while (lenA > lenB) 
    {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) 
    {
        headB = headB->next;
        lenB--;
    }
    while (headA && headB) 
    {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}
int main() 
{
    node *common = new node(8);
    common->next = new node(5);

    vector<int> arrA = {4, 1};
    vector<int> arrB = {5, 6, 1};

    node *headA = ConvertArr2LL(arrA);
    node *tempA = headA;
    while (tempA->next) tempA = tempA->next;
    tempA->next = common;

    node *headB = ConvertArr2LL(arrB);
    node *tempB = headB;
    while (tempB->next) tempB = tempB->next;
    tempB->next = common;

    node *res = getIntersectionNode(headA, headB);
    if (res) cout << "Intersected at " << res->data;
    else cout << "No intersection";
}

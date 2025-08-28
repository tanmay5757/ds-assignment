#include <iostream>
using namespace std;
int main() {
    string yn;
    int number;
    int a[100];
    int n;
    do
    {
        
        cout<<"for creating an array enter 1"<<endl;
        cout<<"for displaying an array enter 2"<<endl;
        cout<<"for detetion an array enter 3"<<endl;
        cout<<"for inserting  an array enter 4"<<endl;
        cout<<"for searching element in an array enter 5"<<endl;
        cin>>number;
        switch (number)
        {
        case 1:
            
            {cout<<"enter no. of elements";
            cin>>n;
            for (int i = 0; i < n; i++)
            {
                cin>>a[i];
            }
            cout<<endl;
            break;}
            
        case 2:
            {for (int i = 0; i < n; i++)
            {
                cout<<a[i]<<" ";

            }
            cout<<endl;
            break;}
        case 3:
            {int index;
            cout<<"enter the index of element to be deleted ";
            cin>>index;
            for (int i = index; i < n-1; i++)
            {
                a[i]=a[i+1];
            }
            n--;
            cout<<endl;
            break;}
        case 4:
        {
            int insert,index2;
            cout<<"enter index and element to insert ";
            cin>>index2>>insert;
            for (int i = n; i >= index2; i--)
            {
                a[i+1]=a[i];

            }
            a[index2]=insert;
            n++;
            break;
        }
        case 5:
        {int find ;
        cout<<"enter element to find";
        cin>>find;
        for (int i = 0; i < n; i++)
        {
            if (a[i]==find)
            {
                cout<<"found at "<<i;
                break;
            }}
            cout<<endl;
            break;
        }
        cout<<endl;
        break;
        cout<<"do you want to start ";
        cin>>yn;
    } while (yn!="no");
    
    return 0;
}

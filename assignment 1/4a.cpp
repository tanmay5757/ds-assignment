#include<iostream>
using namespace std;
void reversearray(int a[],int n)
{
    for(int i=0;i<=n/2;i++)
    {
        int temp=a[i];
        a[i]=a[n-1-i]; // swapping logic
        a[n-1-i]=temp;
    }
    cout << "The reversed array is: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
}
int main()
{
    int size;
    cout << "Enter the size of array: "<<endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array: "<<endl;
    for (int i = 0;i<size;i++) 
    {
        cin >> arr[i];
    }
    cout << "The original array is: \n";
    for (int i = 0; i<size;i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    reversearray(arr,size);
}
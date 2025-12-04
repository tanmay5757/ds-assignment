//binary search in a sorted array
#include<iostream>
using namespace std;

int binarysearch(int n, int a[], int k) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == k) 
            return m;
        else if (k < a[m]) 
            r = m - 1;
        else 
            l = m + 1;
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];
    cout << "\nEnter a sorted array: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nThe sorted array is: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nEnter the number you want to search: \n";
    int num;
    cin >> num;

    int pos = binarysearch(size, arr, num);
    if (pos == -1)
        cout << "\nNumber doesn't exist in array\n";
    else
        cout << "Number found at position " << pos + 1;
    return 0;
}

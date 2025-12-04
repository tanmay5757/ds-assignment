//missing number using binary search
#include <iostream>
using namespace std;
int findmissingbinary(int arr[], int n) {
    int l = 0, r = n - 2;
    while (l<=r) {
        int m = (l+r) / 2;

        if (arr[m] == m + 1) {
            l=m+1;
        } else {
            r = m - 1;
        }
    }
    return l + 1;
}

int main() {
    int n;
    cout << "Enter n :\n";
    cin >> n;
    int arr[n - 1];
    cout << "Enter " << n - 1 << " sorted elements: \n";
    for (int i = 0; i < n - 1; i++) 
    {
        cin >> arr[i];
    }
    cout << "\nMissing number is: " << findmissingbinary(arr, n);
    return 0;
}

//missing number using linear search
#include <iostream>
using namespace std;
int findmissinglinear(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n;
}
int main() {
    int n;
    cout << "Enter n: \n";
    cin >> n;

    int arr[n - 1];
    cout << "Enter " << n - 1 << " sorted elements: \n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    cout << "\nmissing number is: " << findmissinglinear(arr, n);
    return 0;
}

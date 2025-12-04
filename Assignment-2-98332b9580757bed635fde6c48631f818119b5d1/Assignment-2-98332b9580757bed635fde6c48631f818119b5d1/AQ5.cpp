#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) 
    cin >> arr[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) count++;
    }

    int i = n - 1;
    int j = n + count - 1;

    while (i < j) {
        if (arr[i] == 2) {
            if (j < n) arr[j] = 2;
            j--;
            if (j < n) arr[j] = 2;
            j--;
        } else {
            if (j < n) arr[j] = arr[i];
            j--;
        }
        i--;
    }

    cout << "Modified array: ";
    for (int k = 0; k < n; k++) cout << arr[k] << " ";

    return 0;
}

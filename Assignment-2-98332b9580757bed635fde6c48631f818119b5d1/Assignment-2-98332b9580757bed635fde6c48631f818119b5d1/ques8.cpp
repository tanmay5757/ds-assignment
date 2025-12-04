#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: \n";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }

    cout << "Total number of distinct elements: \n" << count;
    return 0;
}

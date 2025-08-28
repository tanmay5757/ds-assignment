#include <iostream>
using namespace std;

int main() {
    int size, arr[100];
    cout << "Enter the size of array:\n ";
    cin >> size;

    cout << "Enter the elements of array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "The original array is: \n";
    for (int i = 0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j< size; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; 
            } else {
                j++;
            }
        }
    }

    cout << "The unique array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
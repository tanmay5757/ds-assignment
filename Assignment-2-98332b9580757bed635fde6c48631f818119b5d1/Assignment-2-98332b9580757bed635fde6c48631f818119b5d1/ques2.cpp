//bubble sort
#include <iostream>
using namespace std;
void bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) //swap occurs here
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: \n";
    for (int i = 0; i < 7; i++) 
    cout << arr[i] << " ";
    bubblesort(arr, 7);
    cout << "\nSorted array:   \n";
    for (int i = 0; i < 7; i++) 
    cout << arr[i] << " ";
    return 0;
}

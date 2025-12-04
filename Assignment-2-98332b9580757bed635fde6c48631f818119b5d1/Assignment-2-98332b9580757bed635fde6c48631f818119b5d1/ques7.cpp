// count inversions in an array
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: \n";
    cin >> n;
    int arr[100];
    cout << "Enter elements of array : \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    cout << "Number of inversions: \n" << count;
    return 0;
}

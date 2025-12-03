//difference qual to k
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size and k: ";
    cin >> n >> k;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  
            if (abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }

    cout << "Number of pairs: " << count;
    return 0;
}

// convert uppercase character to lowercase
#include <iostream>
using namespace std;
int main() {
    char ch;
    cout << "Enter a character: \n";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; 
    }

    cout << "Lowercase character: \n" << ch;
    return 0;
}

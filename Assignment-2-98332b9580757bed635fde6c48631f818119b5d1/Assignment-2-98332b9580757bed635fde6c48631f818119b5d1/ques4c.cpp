// delete vowels from a string
#include <iostream>
using namespace std;
int main() {
    char str[100], result[100];
    cout << "Enter a string: \n";
    cin >> str;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        char c = str[i];
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) 
              {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';
    cout << "String without vowels: \n" << result;
    return 0;
}

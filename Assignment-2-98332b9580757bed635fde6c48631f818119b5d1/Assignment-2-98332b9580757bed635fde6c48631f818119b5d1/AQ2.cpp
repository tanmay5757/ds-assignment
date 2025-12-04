#include <iostream>
#include <cstring>
using namespace std;

bool isSubstring(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) return true;
    }
    return false;
}

int main() {
    char s[100];
    cin >> s;
    int n = strlen(s);
    bool possible = false;

    for (int i = 1; i < n - 1 && !possible; i++) {
        for (int j = i + 1; j < n && !possible; j++) {
            char s1[100], s2[100], s3[100];
            strncpy(s1, s, i);            s1[i] = '\0';
            strncpy(s2, s + i, j - i);    s2[j - i] = '\0';
            strcpy(s3, s + j);

            if ( (isSubstring(s2, s1) && isSubstring(s3, s1)) ||
                 (isSubstring(s1, s2) && isSubstring(s3, s2)) ||
                 (isSubstring(s1, s3) && isSubstring(s2, s3)) ) {
                possible = true;
            }
        }
    }

    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}

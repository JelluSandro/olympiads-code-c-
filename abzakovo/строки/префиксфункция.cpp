#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int p[s.size()] = {0};
    for (int i = 1; i < s.size(); i++) {
        int j = p[i - 1];
        while ((j > 0) && (s[i] != s[j])) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    for (int i = 0; i < s.size(); i++) {
        cout << p[i] << " ";
    }
}

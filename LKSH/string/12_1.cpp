#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p[n];
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int x = p[i - 1];
        while ((x > 0) && (s[i] != s[x])) {
            x = p[x - 1];
        }
        if (s[x] == s[i]) {
            x++;
        }
        p[i] = x;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << n;
}

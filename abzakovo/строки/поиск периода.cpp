#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("period.in", "r", stdin);
    freopen("period.out", "w", stdout);
    string s;
    cin >> s;
    s = s + s;
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
    for (int i = s.size() / 2; i < s.size() - 1; i++)
        if (p[i + 1] - p[i] != 1) {
            cout << s.size() / 2;
            return 0;
        }
    cout << s.size() - p[s.size() - 1];
}

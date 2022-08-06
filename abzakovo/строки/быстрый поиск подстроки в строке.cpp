#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);
    string s, s1;
    cin >> s1 >> s;
    s = s1 + "111" + s;
    int p[s.size()] = {0};
    for (int i = 1; i < s.size(); i++) {
        int j = p[i - 1];
        while ((j > 0) && (s[i] != s[j])) {
            j = p[j - 1];
        }
        if (s[i] == s1[j]) {
            j++;
        }
        p[i] = j;
    }
    int curva = 0;
    for (int i = 0; i < s.size(); i++) {
        if (p[i] == s1.size())
            curva++;
    }

    cout << curva << "\n";
    for (int i = 0; i < s.size(); i++) {
        if (p[i] == s1.size()) {
            cout << i - s1.size() - s1.size() - 1 << " ";
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("z.in", "r", stdin);
    freopen("z.out", "w", stdout);
    string s;
    cin >> s;
    int z[s.size()] = {0};
    int l = 0;
    int r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while ((i + z[i] < s.size()) && (s[z[i]] == s[i + z[i]])) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    for (int i = 1; i < s.size(); i++) {
        cout << z[i] << " ";
    }
}

#include <bits/stdc++.h>

using namespace std;

main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        cout << z[i];
        ans[i + z[i]] = max(z[i], ans[i + z[i]]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << n << " ";
}

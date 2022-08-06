#include <bits/stdc++.h>

using namespace std;

vector<int> zf(string s) {
    int n = s.size();
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
    return z;
}

main() {
    string t, s;
    cin >> t >> s;
    string s1 = t + '#' + s, s2 = s + '#' + t;
    reverse(s2.begin(), s2.end());
    int n = s.size();
    vector<int> z1 = zf(s1), z2 = zf(s2);
    reverse(z2.begin(), z2.end());
    int m = t.size();
    vector<int> ans;
    for (int i = 0; i + m <= n; i++) {
        int pr = z1[m + 1 + i];
        int sf = z2[i + m - 1];
        if (pr + sf >= m - 1) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

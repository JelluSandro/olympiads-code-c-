#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    int INF = 1e18;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int len = (int) sqrt(n + .0) + 1;
    vector<int> b(len, INF);
    for (int i = 0; i < n; ++i)
        b[i / len] = min(a[i], b[i / len]);
    string s;
    while (cin >> s) {
        if (s[0] == 's') {
            int a1, a2;
            cin >> a1 >> a2;
            a1--;
            a[a1] = a2;
            b[a1 / len] = INF;
            for (int i = (a1 / len) * len; i < min((a1 / len) * len + len, n); ++i)
                b[i / len] = min(a[i], b[i / len]);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int sum = INF;
            for (int i = l; i <= r;)
                if (i % len == 0 && i + len - 1 <= r) {
                    sum = min(b[i / len], sum);
                    i += len;
                } else {
                    sum = min(a[i], sum);
                    ++i;
                }
            cout << sum << endl;
        }
    }
}

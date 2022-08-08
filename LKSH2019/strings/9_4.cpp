#include <bits/stdc++.h>

using namespace std;
#define  int  long long

main() {
    int md = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    int pp = 37;
    vector<int> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = (p[i - 1] * (107)) % md;
    }
    vector<int> pr(n);
    vector<int> sf(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pr[i] = (a[i] * p[i]) % md;
        if (i != 0) {
            pr[i] = (pr[i] + pr[i - 1]) % md;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        sf[i] = (a[i] * p[n - i - 1]) % md;
        if (i != n - 1) {
            sf[i] = (sf[i] + sf[i + 1]) % md;
        }
    }
    vector<int> ans;
    ans.push_back(n);
    for (int i = 0; i < n / 2; i++) {
        int x = (pr[i] * p[n - 2 * i - 2]) % md;
        int y = sf[i + 1];
        if (2 * i + 2 < n) {
            y = (md + (y - sf[2 * i + 2]) % md) % md;
        }
        if (x == y) {
            ans.push_back(n - i - 1);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

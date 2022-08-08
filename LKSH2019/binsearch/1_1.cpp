#include <bits/stdc++.h>

using namespace std;
#define int long long

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("kbest.in", "r", stdin);
    //freopen("kbest.out", "w", stdout);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<long double> u(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> w[i];
    }
    long double l = 0, r = 1e9;
    long double b[n];
    for (int ii = 0; ii < 50; ii++) {
        long double m = (l + r) / 2;
        long double sum = 0;
        for (int i = 0; i < n; i++) {
            b[i] = u[i] - w[i] * m;
        }
        sort(b, b + n);
        for (int i = n - 1; i > n - 1 - k; i--) {
            sum += b[i];
        }
        if (sum >= 0) {
            l = m;
        } else {
            r = m;
        }
    }
    vector <pair<long double, int>> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i].first = u[i] - w[i] * l;
        ans[i].second = i + 1;
    }
    sort(ans.begin(), ans.end());
    for (int i = n - 1; i > n - 1 - k; i--) {
        cout << ans[i].second << " ";
    }
}

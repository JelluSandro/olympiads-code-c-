#include <bits/stdc++.h>
using namespace std;
long long a[20][20];
int main() {
    long long INF = 1e18;
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = INF;
        }
    }
    for (int  i = 0; i < m; i++) {
        long long a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a1--;
        a2--;
        a[a1][a2] = a3;
        a[a2][a1] = a3;
    }
    vector < vector < long long > > dp((1 << n), vector < long long >(n, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[(1 << i)][i] = 0;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }
            if (dp[mask][i] == INF) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if ((mask & (1 << k)) == 0) {
                    dp[(mask | (1 << k))][k] = min(dp[(mask | (1 << k))][k], dp[mask][i] + a[i][k]);
                }
            }
        }
    }
    long long mx = INF;
    for (int i = 0; i < n; i++) {
        mx = min(mx, dp[(1 << n) - 1][i]);
    }
    if (mx == INF) {
        cout << -1;
        return 0;
    }
    cout << mx;
}
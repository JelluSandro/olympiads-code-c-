#include <bits/stdc++.h>

#define int long long
using namespace std;
int const INF = 1e9;
int const nx = 17;
int d[nx][nx];
int dp[(1 << nx)][nx];
int pr[(1 << nx)][nx];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
            if (d[i][j] == 0) {
                d[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
            pr[i][j] = -1;
        }
    }
    dp[1][0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int v = 0; v < n; v++) {
            if ((mask & (1 << v)) == (1 << v)) {
                for (int u = 0; u < n; u++) {
                    if ((mask & (1 << u)) == (1 << u)) {
                        if (dp[mask][v] > dp[mask ^ (1 << v)][u] + d[u][v]) {
                            dp[mask][v] = dp[mask ^ (1 << v)][u] + d[u][v];
                            pr[mask][v] = u;
                        }
                    }
                }
            }
        }
    }
    int mn = INF, m = -1;
    for (int i = 0; i < n; i++) {
        if (dp[(1 << n) - 1][i] < mn) {
            mn = dp[(1 << n) - 1][i];
            m = i;
        }
    }
    vector<int> ans;
    ans.push_back(m + 1);
    if (mn == INF) {
        cout << -1;
        return 0;
    }
    int mask = (1 << n) - 1;
    int c = m;
    for (;;) {
        ans.push_back(c);
        int pp = c;
        c = pr[mask][c];
        if (c == -1) { break; }
        mask = mask ^ (1 << pp);
    }
    reverse(ans.begin(), ans.end());
    cout << mn << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
}

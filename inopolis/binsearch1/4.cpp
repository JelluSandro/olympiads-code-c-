#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    int n, m;
    cin >> n >> m;
    int a1;
    cin >> a1;
    int u, v;
    cin >> u >> v;
    int a[n + 1];
    a[1] = a1;
    for (int i = 2; i <= n; i++) {
        a[i] = (23 * a[i - 1] + 21563) % 16714589;
    }
    int st[35];
    st[0] = 1;
    int lg[n + 1];
    lg[0] = 0;
    lg[1] = 0;
    lg[2] = 1;
    lg[3] = 1;
    for (int i = 4; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i < 35; i++) {
        st[i] = st[i - 1] * 2;
    }
    int dp[35][n + 1];
    for (int i = 1; i <= n; i++) {
        dp[0][i] = a[i];
    }

    for (int i = 1; i < 35; i++) {
        for (int j = 1; j <= n; j++) {
            if (j + st[i - 1] <= n)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + st[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 1; i <= m - 1; i++) {
        int u1 = u;
        int v1 = v;
        if (u > v) {
            swap(u, v);
        }
        int ans = min(dp[lg[v - u + 1]][u], dp[lg[v - u + 1]][v - st[lg[v - u + 1]] + 1]);

        u = u1;
        v = v1;
        u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i) % n) + 1;

    }
    cout << u << " " << v << " ";
    if (u > v)
        swap(u, v);
    cout << min(dp[lg[v - u + 1]][u], dp[lg[v - u + 1]][v - st[lg[v - u + 1]] + 1]);

}

#include <bits/stdc++.h>

using namespace std;

int gg[3000][3000];

int main() {
    freopen("lcs.in", "r", stdin);
    freopen("lcs.out", "w", stdout);
    int const mix = 1000000000;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {

        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= m; j++) {

            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {
            int k1 = dp[i - 1][j];
            int k2 = dp[i][j - 1];
            int k3 = (dp[i - 1][j - 1] + 1) * (int) (a[i - 1] == b[j - 1]);
            if ((k1 >= k2) && (k1 >= k3)) {
                gg[i][j] = 1;
                dp[i][j] = k1;
            } else {
                if ((k2 >= k1) && (k2 >= k3)) {

                    gg[i][j] = 2;
                    dp[i][j] = k2;
                } else {
                    gg[i][j] = 3;
                    dp[i][j] = k3;
                }
            }
        }

    }

    cout << dp[n][m] << "\n";
    int i1 = n;
    int j1 = m;
    vector<int> gop(max(n, m));
    int cur = 0;
    while ((i1 != 0) && (j1 != 0)) {

        if (gg[i1][j1] == 1) {

            i1--;
        } else {

            if (gg[i1][j1] == 2) {
                j1--;
            } else {
                gop[cur] = a[i1 - 1];
                cur++;
                i1--;
                j1--;
            }
        }
    }

    for (int i = cur - 1; i >= 0; i--) {
        cout << gop[i] << " ";
    }


}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int md = 1e9;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector < vector < int > > dp(n, vector < int >(n, 0));
    for (int l = 0; l < n; l++) {
        for (int i = 0; i + l < n; i++) {
            int r = i + l;
            dp[i][r] = 0;
            if (r - 1 >= 0) {
                dp[i][r] = (dp[i][r] + dp[i][r - 1]) % md;
            }
            if (i + 1 < n) {
                dp[i][r] = (dp[i][r] + dp[i + 1][r]) % md;
            }
            if(r - 1 >= 0 && i + 1 < n) {
                dp[i][r] = (dp[i][r] - dp[i + 1][r - 1] + md) % md;
            }
            if (a[i] != a[r]) {
                continue;
            }
            dp[i][r]++;
            if (i + 1 <= r - 1) {
                dp[i][r] = (dp[i][r] + dp[i + 1][r - 1]) % md;
            }
        }
    }
    cout << dp[0][n - 1];
}
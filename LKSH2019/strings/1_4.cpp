#include <bits/stdc++.h>

using namespace std;
#define int long long

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int dp[n][n];
    string st[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
            st[i][j] = "";
        }
    }
    for (int len = 0; len < n; len++) {
        for (int l = 0; l + len < n; l++) {
            int r = l + len;
            for (int k = l; k < r; k++) {
                if (dp[l][r] < dp[l][k] + dp[k + 1][r]) {
                    dp[l][r] = dp[l][k] + dp[k + 1][r];
                    st[l][r] = st[l][k] + st[k + 1][r];
                }
            }
            if ((s[l] == '{' && s[r] == '}' || s[l] == '[' && s[r] == ']' || s[l] == '(' && s[r] == ')') &&
                (dp[l][r] < dp[l + 1][r - 1] + 1)) {
                dp[l][r] = dp[l + 1][r - 1] + 1;
                st[l][r] = s[l] + st[l + 1][r - 1] + s[r];
            }
        }
    }
    cout << st[0][n - 1];
}

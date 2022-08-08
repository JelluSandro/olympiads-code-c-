#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    vector < vector < int > > dp(n + 1, vector < int >(m + 1, 0));
    for (int i = 1; i < m + 1; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i < n + 1; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (s[i - 1] != t[j - 1]) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[n][m];
}
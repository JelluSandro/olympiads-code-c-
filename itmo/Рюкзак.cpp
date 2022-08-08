#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main() {
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector < int > w(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector < vector < int > > dp(n + 1, vector < int >(m + 1, 0));
    vector < vector < int > > pr(n + 1, vector < int >(m + 1, -1));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i != 0) {
                dp[i][j] = dp[i - 1][j];
                pr[i][j] = -2;
            }
            if (i != 0 && j - w[i - 1] >= 0 && dp[i][j] < dp[i - 1][j - w[i - 1]] + c[i - 1]) {
                dp[i][j] = dp[i - 1][j - w[i - 1]] + c[i - 1];
                pr[i][j] = i - 1;
            }
        }
    }
    int x = n, y = m;
    vector < int > ans;
    while (pr[x][y] != -1) {
        if (pr[x][y] >= 0) {
            ans.push_back(pr[x][y]);
            int xx = pr[x][y];
            y -= w[pr[x][y]];
            x = xx;
        }
        if (pr[x][y] == -2) {
            x--;
            if (x < 0) {
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
}
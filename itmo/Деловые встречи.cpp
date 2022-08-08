#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main() {
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector < int > dp((1 << n), -1);
    vector < int > a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == -1) {
            continue;
        }
        int cnt = k;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == (1 << j)) {
                cnt += c[j];
            }
        }
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0) {
                if (a[j] <= cnt && cnt <= b[j]) {
                    dp[(mask | (1 << j))] = j;
                }
            }
        }
    }
    int mx = 0, z = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (dp[i] == -1) {
            continue;
        }
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == (1 << j)) {
                cur++;
            }
        }
        if (cur > mx) {
            mx = cur;
            z = i;
        }
    }
    cout << mx << "\n";
    vector < int > ans;
    mx = z;
    while (mx != 0) {
        ans.push_back(dp[mx]);
        mx = (mx ^ (1 << dp[mx]));
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
}
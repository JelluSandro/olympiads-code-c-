#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int x = 1;
    int cnt = 0;
    while (n > x) {
        cnt++;
        x *= 2;
    }
    cnt--;
    x = x / 2;
    pair<int, int> dp[n - x + 1];
    for (int i = 0; i < n - x + 1; i++) {
        dp[i].first = 1e7;
    }
    dp[0].first = cnt;
    for (int i = 1; i <= n - x; i++) {
        for (int j = 1; j <= i; j++) {
            if ((x + i) % j == 0) {
                if (dp[i - j].first + 1 < dp[i].first) {
                    dp[i].first = dp[i - j].first + 1;
                    dp[i].second = j;
                }
            }
        }
    }
    cout << dp[n - x].first << endl;
    int s = n;
    for (;;) {
        cout << dp[s - x].second << " ";
        s = s - dp[s - x].second;
        if (s == x) {
            break;
        }
    }
    while (x != 1) {
        x = x / 2;
        cout << x << " ";
    }

}

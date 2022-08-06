#include <bits/stdc++.h>

using namespace std;

int main() {
    int INF = 1e9;
    int n, a0, k, b, m;
    cin >> n >> a0 >> k >> b >> m;
    n++;
    int a[n];
    a[0] = a0;
    for (int i = 1; i < n - 1; i++) {
        a[i] = (k * a[i - 1] + b) % m;
    }
    vector<int> dp(n, INF);
    for (int i = 0; i < n - 1; i++) {
        int l = 0, r = n - 1;
        for (int j = 0; j < 100; j++) {
            int m = (l + r) / 2;
            if (dp[m] < a[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        dp[r] = a[i];
    }
    for (int i = 0; i < n; i++) {
        if (dp[i] == INF) {
            cout << i;
            break;
        }
    }
}

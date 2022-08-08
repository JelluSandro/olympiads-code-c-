#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m, a1;
    cin >> n >> m >> a1;
    int u, v;
    cin >> u >> v;
    vector < int > a(n);
    a[0] = a1;
    for (int i = 0; i < n - 1; i++) {
        a[i + 1] = (23 * a[i] + 21563) % 16714589;
    }
    vector < vector < int > > st(n, vector < int > (25, 16714589));
 
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
 
    for (int j = 1; j < 25; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (i != 0) {
            u = (17 * u + 751 + ans + 2 * (i)) % n + 1;
            v = (13 * v + 593 + ans + 5 * (i)) % n + 1;
        }
        int l = min(u, v) - 1;
        int r = max(u, v) - 1;
        int mn = 16714589;
        for (int j = 25; j >= 0; j--) {
            if (l + (1 << j) <= r + 1) {
                mn = min(st[l][j], mn);
                l += 1 << j;
            }
        }
        ans = mn;
    }
    cout << u << " " << v << " " << ans;
}
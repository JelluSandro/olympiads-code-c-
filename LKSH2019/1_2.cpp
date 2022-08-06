#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
vector <vector<int>> g;
vector<int> us;
vector<int> a;
int ans = 0;
vector<int> b;

void cyc(int v) {
    us[v] = 1;
    for (auto to : g[v]) {
        if (us[to] == 1) {
            cout << -1;
            exit(0);
        }
        if (us[to] == 0) {
            cyc(to);
        }
    }
    us[v] = 2;
}

void dfs(int v) {
    us[v] = 1;
    for (auto to : g[v]) {
        if (us[to] == 0) {
            dfs(to);
        }
        b[v] = max(b[v], b[to] + (a[v] < a[to] ? 1 : 0));
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n, 0);
    for (int i = 0; i < n; i++) {
        int a1;
        cin >> a1;
        a1--;
        a[a1] = i;
    }
    g.resize(n);
    us.resize(n, 0);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a1;
            cin >> a1;
            a1--;
            g[i].push_back(a1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (us[i] == 0) {
            cyc(i);
        }
    }
    us.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (us[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, b[i]);
    }
    cout << ans + 1;
}

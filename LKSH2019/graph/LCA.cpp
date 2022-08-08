#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, l;
vector <vector<int>> g;
vector<int> tin, tout;
int timer;
int const INF = 1e9;
vector <vector<int>> up;
vector <vector<int>> dist;
vector <vector<int>> d;
vector<int> h;

void dfs(int v, int p = 0, int pp = 0, int cnt = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    d[v][0] = pp;
    h[v] = cnt;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        d[v][i] = min(d[up[v][i - 1]][i - 1], d[v][i - 1]);
    }
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p) {
            dfs(to, v, dist[v][i], cnt + 1);
        }
    }
    tout[v] = ++timer;
}

int lca(int a, int b) {
    int cnt = INF;
    if (h[a] < h[b]) {
        swap(a, b);
    }
    for (int i = l; i >= 0; --i) {
        if (h[up[a][i]] >= h[b]) {
            cnt = min(cnt, d[a][i]);
            a = up[a][i];
            // cout<<a<<" " <<i<<" "<<d[a][i]<<endl;
        }
    }
    if (a == b)
        return cnt;
    for (int i = l; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            cnt = min(cnt, d[a][i]);
            cnt = min(cnt, d[b][i]);
            a = up[a][i];
            b = up[b][i];
        }
    }
    cnt = min(cnt, d[a][0]);
    cnt = min(cnt, d[b][0]);
    return (cnt);
}

signed main() {
    cin >> n;
    g.resize(n);
    dist.resize(n);
    h.resize(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        g[i + 1].push_back(a1);
        g[a1].push_back(i + 1);
        dist[i + 1].push_back(a2);
        dist[a1].push_back(a2);
    }

    tin.resize(n), tout.resize(n), up.resize(n);
    l = 1;
    d.resize(n);

    while ((1 << l) <= n) ++l;
    for (int i = 0; i < n; ++i) {
        up[i].resize(l + 1, 0);
        d[i].resize(l + 1, -1);
    }
    dfs(0, 0, INF, 0);
    for (int i = 0; i < n; i++) {
        int gg = 0;
        for (int j = 0; j <= l; j++) {
            if (d[i][j] != -1) {
                gg = d[i][j];
            } else {
                d[i][j] = gg;
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int res = lca(a, b);
        cout << res << endl;
    }
}

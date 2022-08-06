#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second

vector <vector<int>> g;
vector <vector<int>> gt;
vector<int> order;
vector<int> comp;
vector<int> used;

void dfs1(int v) {
    used[v] = 1;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs1(to);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (size_t i = 0; i < gt[v].size(); ++i) {
        int to = gt[v][i];
        if (comp[to] == -1)
            dfs2(to, cl);
    }
}

void solve() {
    int n;
    while (cin >> n) {
        int m;
        cin >> m;
        g.resize(2 * n);
        gt.resize(2 * n);
        for (int i = 0; i < m; i++) {
            int i1, e1, i2, e2;
            cin >> i1 >> e1 >> i2 >> e2;
            int x1 = i1 * 2 + e1;
            int x2 = i2 * 2 + e2;
            g[x1 ^ 1].push_back(x2);
            g[x2 ^ 1].push_back(x1);
            gt[x1].push_back(x2 ^ 1);
            gt[x2].push_back(x1 ^ 1);
        }
        used.resize(2 * n, 0);
        for (int i = 0; i < 2 * n; ++i) {
            if (!used[i]) {
                dfs1(i);
            }
        }
        comp.resize(2 * n, -1);
        for (int i = 0, j = 0; i < 2 * n; ++i) {
            int v = order[2 * n - i - 1];
            if (comp[v] == -1) {
                dfs2(v, j++);
            }
        }
        for (int i = 0; i < 2 * n; i += 2) {
            int ans = comp[i] > comp[i ^ 1] ? 0 : 1;
            cout << ans;
        }
        cout << endl;
        g.clear();
        gt.clear();
        order.clear();
        comp.clear();
        used.clear();
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

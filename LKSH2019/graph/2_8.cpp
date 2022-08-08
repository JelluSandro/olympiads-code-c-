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
vector<char> cl;

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
    int n, m;
    cin >> n >> m;
    cl.resize(n);
    vector<char> paint(2 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cl[i];
        char a1, a2;
        if (cl[i] == 'R') {
            a1 = 'G';
            a2 = 'B';
        }
        if (cl[i] == 'B') {
            a1 = 'G';
            a2 = 'R';
        }
        if (cl[i] == 'G') {
            a1 = 'R';
            a2 = 'B';
        }
        paint[i * 2] = a1;
        paint[i * 2 + 1] = a2;
    }
    g.resize(2 * n);
    gt.resize(2 * n);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        int x1 = a1 * 2, x2 = a2 * 2;
        if (paint[x1] == paint[x2]) {
            g[x1].push_back(x2 ^ 1);
            g[x2].push_back(x1 ^ 1);
            gt[x2 ^ 1].push_back(x1);
            gt[x1 ^ 1].push_back(x2);
        }
        x2 = x2 ^ 1;
        if (paint[x1] == paint[x2]) {
            g[x1].push_back(x2 ^ 1);
            g[x2].push_back(x1 ^ 1);
            gt[x2 ^ 1].push_back(x1);
            gt[x1 ^ 1].push_back(x2);
        }
        x1 = x1 ^ 1;
        if (paint[x1] == paint[x2]) {
            g[x1].push_back(x2 ^ 1);
            g[x2].push_back(x1 ^ 1);
            gt[x2 ^ 1].push_back(x1);
            gt[x1 ^ 1].push_back(x2);
        }
        x2 = x2 ^ 1;
        if (paint[x1] == paint[x2]) {
            g[x1].push_back(x2 ^ 1);
            g[x2].push_back(x1 ^ 1);
            gt[x2 ^ 1].push_back(x1);
            gt[x1 ^ 1].push_back(x2);
        }
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
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i ^ 1]) {
            cout << "Impossible";
            return;
        }
    }
    for (int i = 0; i < 2 * n; i += 2) {
        int ans = comp[i] > comp[i ^ 1] ? i : i ^ 1;
        cout << paint[ans];
    }
}

main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

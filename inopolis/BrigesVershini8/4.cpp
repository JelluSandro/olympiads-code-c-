#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, m;
vector <vector<int>> g, gr;
vector<int> sa;
vector<int> sb;
vector<char> used;
vector<int> order, component;
int ot = 0;
int mx = 0;
int ok = 0;

void dfs1(int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs1(g[v][i]);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component[v] = ok;
    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!used[gr[v][i]])
            dfs2(gr[v][i]);
}

main() {
    cin >> n >> m;
    g.resize(n);
    gr.resize(n);
    sa.resize(m);
    sb.resize(m);
    used.resize(n, 0);
    component.resize(n);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        g[a1].push_back(a2);
        gr[a2].push_back(a1);
        sa[i] = a1;
        sb[i] = a2;
    }
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs2(v);
            ok++;
        }
    }
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        if (component[sa[i]] != component[sb[i]]) {
            int xx = component[sa[i]] * 1e5 + component[sb[i]];
            int yx = component[sa[i]] + component[sb[i]] * 1e5;
            if (mp[xx] != 1) {
                mx++;
                mp[xx] = 1;
                mp[yx] = 1;
            }
        }
    }
    cout << mx;
}

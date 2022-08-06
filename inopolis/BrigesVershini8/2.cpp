#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, m, ok = 0;
vector <vector<int>> g;
vector <vector<int>> b;
vector <vector<int>> g1;
vector<int> og;
vector<int> sa;
vector<int> sb;
vector<int> ot;
vector<int> used;
vector<int> tin;
vector<int> fup;
int timer = 0;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v])
                ot.push_back(b[v][i]);
        }
    }
}

void dfs1(int v) {
    used[v] = 1;
    og[v] = ok;
    for (int i = 0; i < g1[v].size(); i++) {
        if (used[g1[v][i]] == 0) {
            dfs1(g1[v][i]);
        }
    }
}

main() {
    cin >> n >> m;
    g.resize(n);
    g1.resize(n);
    b.resize(n);
    used.resize(n, 0);
    tin.resize(n);
    fup.resize(n);
    og.resize(n);
    sa.resize(m);
    sb.resize(m);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        sa[i] = a1;
        sb[i] = a2;
        g[a1].push_back(a2);
        g[a2].push_back(a1);
        b[a1].push_back(i);
        b[a2].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i, -1);
        }
    }
    sort(ot.begin(), ot.end());
    int cnt = 0;
    if (ot.size() > 0) {
        for (int i = 0; i < m; i++) {
            if (i != ot[cnt]) {
                g1[sb[i]].push_back(sa[i]);
                g1[sa[i]].push_back(sb[i]);
            } else {
                cnt++;
                if (cnt == ot.size()) {
                    cnt = 0;
                }
            }
        }
    } else {
        for (int i = 0; i < m; i++) {
            g1[sb[i]].push_back(sa[i]);
            g1[sa[i]].push_back(sb[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs1(i);
            ok++;
        }
    }
    cout << ok << endl;
    for (int i = 0; i < n; i++) {
        cout << og[i] + 1 << " ";
    }
}

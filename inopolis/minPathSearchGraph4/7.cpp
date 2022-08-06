#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, m, s, f;
vector <vector<int>> g;
vector <vector<int>> b;
vector<bool> used;
vector<int> ans;
vector<int> tg;
vector<int> ot;

void dfs(int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
    ans.push_back(v);
}

void topological_sort() {
    for (int i = 0; i < n; ++i)
        used[i] = false;
    ans.clear();
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
}

void din(int v) {
    if (ot[ans[v]] != 5e18) {
        for (int i = 0; i < g[ans[v]].size(); i++) {
            ot[g[ans[v]][i]] = min(ot[g[ans[v]][i]], ot[ans[v]] + b[ans[v]][i]);
        }
    }
    if (v + 1 <= tg[f]) {
        din(v + 1);
    }
}

void dfs1(int v, int ves) {
    ot[v] = min(ot[v], ves);
    for (int i = 0; i < g[i].size(); i++) {
        if ((tg[v] < tg[g[v][i]]) && (tg[g[v][i]] <= tg[f])) {
            dfs1(g[v][i], ot[v] + b[v][i]);
        }
    }
}

main() {
    cin >> n >> m >> s >> f;
    s--;
    f--;
    g.resize(n);
    b.resize(n);
    tg.resize(n);
    ot.resize(n, 5e18);
    used.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a1--;
        a2--;
        g[a1].push_back(a2);
        b[a1].push_back(a3);
    }
    topological_sort();
    int st = 0, ft = 0;
    for (int i = 0; i < ans.size(); i++) {
        tg[ans[i]] = i;
    }
    ot[s] = 0;
    din(tg[s]);
    if (ot[f] == 5e18) {
        cout << "Unreachable";
    } else {
        cout << ot[f];
    }
}

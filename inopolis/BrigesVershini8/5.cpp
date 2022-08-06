#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, m;
vector <vector<int>> g;
vector<int> c;
vector<int> ot;
vector<int> used;
vector<int> tin;
vector<int> fup;
int timer = 0;

void dfs(int v, int p = -1) {
    used[v] = true;
    timer++;
    tin[v] = timer;
    fup[v] = timer;
    int children = 0;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1) {
                if (c[v] == 0) {
                    ot.push_back(v);
                    c[v] = 1;
                }
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        if (c[v] == 0) {
            ot.push_back(v);
            c[v] = 1;
        }
    }
}

main() {
    cin >> n >> m;
    int nn = 4e5;
    g.resize(nn);
    used.resize(nn, 0);
    c.resize(nn, 0);
    tin.resize(nn);
    fup.resize(nn);
    for (int i = 0; i < m; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a1--;
        a2--;
        a3--;
        g[a1].push_back(i + n);
        g[a2].push_back(i + n);
        g[a3].push_back(i + n);
        g[i + n].push_back(a1);
        g[i + n].push_back(a2);
        g[i + n].push_back(a3);
    }
    for (int i = 0; i < nn; i++) {
        if (used[i] == 0) {
            dfs(i, -1);
        }
    }
    vector<int> oot;
    for (int i = 0; i < ot.size(); i++) {
        if (ot[i] - n >= 0) {
            oot.push_back(ot[i]);
        }
    }
    cout << oot.size() << endl;
    sort(oot.begin(), oot.end());
    for (int i = 0; i < oot.size(); i++) {
        cout << oot[i] - n + 1 << " ";
    }
}

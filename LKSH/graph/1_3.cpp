#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <vector<int>> g;
vector <vector<int>> b;
vector<int> ot;
vector<int> used;
vector<int> tin;
vector<int> fup;
int timer = 0;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                ot.push_back(b[v][i]);
            }
        }
    }
}

main() {
    cin >> n >> m;
    g.resize(n);
    b.resize(n);
    used.resize(n, 0);
    tin.resize(n);
    fup.resize(n);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        g[a1].push_back(a2);
        g[a2].push_back(a1);
        b[a1].push_back(i + 1);
        b[a2].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i, -1);
        }
    }
    cout << (int) ot.size() << endl;
    sort(ot.begin(), ot.end());
    for (int i = 0; i < (int) ot.size(); i++) {
        cout << ot[i] << " ";
    }
}

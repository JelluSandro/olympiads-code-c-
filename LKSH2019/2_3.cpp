#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second

int n, m;
vector <vector<int>> graf;
vector<int> u;
vector<int> tin;
vector<int> fup;
int tim = 1;
set<int> ans;

void dfs(int v, int p = -1) {
    u[v] = 1;
    tin[v] = tim;
    fup[v] = tim;
    tim++;
    int child = 0;
    for (int i = 0; i < graf[v].size(); i++) {
        int to = graf[v][i];
        if (to == p) { continue; }
        if (u[to] == 1) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            child++;
            fup[v] = min(fup[v], fup[to]);
            if (tin[v] <= fup[to] && p != -1) {
                if (v < m) ans.insert(v);
            }
        }
    }
    if (child > 1 && p == -1) {
        if (v < m) ans.insert(v);
    }
}

void solve() {
    cin >> n >> m;
    graf.resize(n + m + 1);
    u.resize(n + m + 1, 0);
    tin.resize(n + m + 1);
    fup.resize(n + m + 1);
    for (int i = 0; i < m; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a1 += m - 1;
        a2 += m - 1;
        a3 += m - 1;
        graf[a1].push_back(i);
        graf[a2].push_back(i);
        graf[a3].push_back(i);
        graf[i].push_back(a1);
        graf[i].push_back(a2);
        graf[i].push_back(a3);
    }
    dfs(0);
    cout << ans.size() << "\n";
    for (int it : ans) {
        cout << it + 1 << " ";
    }
}

main() {
    freopen("city.in", "r", stdin);
    freopen("city.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}


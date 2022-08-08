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
                ans.insert(v);
            }
        }
    }
    if (child > 1 && p == -1) {
        ans.insert(v);
    }
}

void solve() {
    cin >> n >> m;
    graf.resize(n);
    u.resize(n);
    tin.resize(n);
    fup.resize(n);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        graf[a1].push_back(a2);
        graf[a2].push_back(a1);
    }
    for (int i = 0; i < n; i++) {
        if (u[i] == 0) {
            dfs(i);
        }
    }
    cout << ans.size() << "\n";
    for (int it : ans) {
        cout << it + 1 << " ";
    }
}

main() {
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}


#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second

vector <vector<int>> graf;
vector <vector<int>> reb;
vector<int> u;
vector<int> ans;
vector<int> tin;
vector<int> up;
int tim = 1;
int n, m;

void dfs(int v, int p = -1) {
    u[v] = 1;
    tin[v] = tim;
    up[v] = tim;
    tim++;
    for (int i = 0; i < graf[v].size(); i++) {
        int to = graf[v][i];
        if (to == p) continue;
        if (u[to] == 1) {
            up[v] = min(up[v], tin[to]);
        } else {
            dfs(to, v);
            up[v] = min(up[v], up[to]);
            if (tin[v] < up[to]) {
                ans.push_back(reb[v][i]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    graf.resize(n);
    u.resize(n, 0);
    tin.resize(n);
    up.resize(n);
    reb.resize(n);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        graf[a1].push_back(a2);
        graf[a2].push_back(a1);
        reb[a1].push_back(i + 1);
        reb[a2].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        if (u[i] == 0) {
            dfs(i, -1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

main() {
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}


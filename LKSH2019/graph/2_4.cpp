#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second

int n, m;
vector <vector<int>> graf;
vector <vector<int>> rb;
deque <pair<int, int>> d;
vector<int> u;
vector<int> tin;
vector<int> fup;
int tim = 1;
vector<int> color;
int paint = 0;
vector<int> us;

void dfs(int v, int p = -1) {
    u[v] = 1;
    tin[v] = tim;
    fup[v] = tim;
    tim++;
    int child = 0;
    for (int i = 0; i < graf[v].size(); i++) {
        int to = graf[v][i];
        if (to == p) {
            if (us[rb[v][i]] == 0) {
                d.push_front({v, i});
                us[rb[v][i]] = 1;
            }
            continue;
        }
        if (u[to] == 1) {
            if (us[rb[v][i]] == 0) {
                d.push_front({v, i});
                us[rb[v][i]] = 1;
            }
            fup[v] = min(fup[v], tin[to]);
        } else {
            if (us[rb[v][i]] == 0) {
                d.push_front({v, i});
                us[rb[v][i]] = 1;
            }
            dfs(to, v);
            child++;
            fup[v] = min(fup[v], fup[to]);
            if (tin[v] <= fup[to] && p != -1) {
                if (d.size() > 0) paint++;
                for (;;) {
                    if (d.size() > 0) {
                        pair<int, int> x = d.front();
                        d.pop_front();
                        color[rb[x.ff][x.ss]] = paint;
                        if (x.ff == v) {
                            break;
                        }
                    } else break;
                }
            }
        }
    }
    if (child > 1 && p == -1) {
        while (d.size() > 0) {
            if (d.size() > 0) paint++;
            for (;;) {
                if (d.size() > 0) {
                    pair<int, int> x = d.front();
                    d.pop_front();
                    color[rb[x.ff][x.ss]] = paint;
                    if (x.ff == v) {
                        break;
                    }
                } else break;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    graf.resize(n);
    u.resize(n);
    tin.resize(n, 1e6);
    fup.resize(n);
    color.resize(m);
    us.resize(m, 0);
    rb.resize(n);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        graf[a1].push_back(a2);
        graf[a2].push_back(a1);
        rb[a1].push_back(i);
        rb[a2].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (u[i] == 0) {
            dfs(i);
        }
        if (d.size() > 0) paint++;
        for (;;) {
            if (d.size() > 0) {
                pair<int, int> x = d.front();
                d.pop_front();
                color[rb[x.ff][x.ss]] = paint;
            } else break;
        }
    }
    cout << paint << "\n";
    for (int i = 0; i < m; i++) {
        cout << color[i] << " ";
    }
}

main() {
    freopen("biconv.in", "r", stdin);
    freopen("biconv.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

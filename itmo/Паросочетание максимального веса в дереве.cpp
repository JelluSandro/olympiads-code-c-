#include <bits/stdc++.h>
using namespace std;
vector < vector < int > > g;
vector < vector < long long > > w;
vector < long long > dp;
vector < long long > pp;
void dfs(int v, int p) {
    long long s = 0;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        dfs(to, v);
        s += max(dp[to], pp[to]);
    }
    pp[v] = s;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        if (dp[to] > pp[to]) {
            dp[v] = max(dp[v], s - dp[to] + pp[to] + w[v][i]);
        } else {
            dp[v] = max(dp[v], s + w[v][i]);
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    w.resize(n);
    dp.resize(n, 0);
    pp.resize(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int a1, a2;
        long long a3;
        cin >> a1 >> a2 >> a3;
        a1--;
        a2--;
        g[a1].push_back(a2);
        w[a1].push_back(a3);
        g[a2].push_back(a1);
        w[a2].push_back(a3);
    }
    dfs(0, -1);
    cout << max(pp[0], dp[0]);
}
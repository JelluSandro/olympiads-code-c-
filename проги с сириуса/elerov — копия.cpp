#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second

vector<int> u;
int n;
vector<int> ans;
vector<vector<pair<int, int> > > rb;

void dfs(int v) {
    while (rb[v].size()) {
        if (u[rb[v].back().ss] == 0) {
            u[rb[v].back().ss] = 1;
            int to = rb[v].back().ff;
            rb[v].pop_back();
            dfs(to);
        } else {
            rb[v].pop_back();
        }
    }
    ans.push_back(v);
}

void solve() {
    cin >> n;
    rb.resize(n);
    int x = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (m % 2 == 1) {
            x = i;
        }
        for (int j = 0; j < m; j++) {
            int a1;
            cin >> a1;
            a1--;
            if (i <= a1) {
                rb[i].push_back({a1, cnt});
                rb[a1].push_back({i, cnt});
                cnt++;
            }
        }
    }
    u.resize(cnt, 0);
    dfs(x);
    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
}

main() {
   // freopen("euler.in", "r", stdin);
   // freopen("euler.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

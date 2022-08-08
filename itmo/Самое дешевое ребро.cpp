#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int> > g;
vector<vector<int> > gv;
vector<int> used;
vector<int> vx;
vector<int> vi;
vector<int> pr;
int ott;
int otv;
int d[200002][50];
int dp[200002][50];
int n, s;
int cnt = 0;
int cur = 0;
 
void dfs(int v) {
    used[v] = 1;
    vx[v] = cnt;
    cnt++;
    for (int i = 0; i < (int)g[v].size(); i++) {
        if (used[g[v][i]] == 0) {
            dp[g[v][i]][0] = gv[v][i];
            pr[g[v][i]] = v;
            dfs(g[v][i]);
        }
    }
    vi[v] = cnt;
    cnt++;
}
 
void f(int a1, int a2) {
    ott = a1;
    if (cur > 0)
        otv = min(otv, dp[a1][0]);
    else
        otv = dp[a1][0];
    cur++;
    for (int i = 24; i >= 0; i--) {
        int v = d[a1][i];
        if ((vx[v] > vx[a2]) || (vi[v] < vi[a2])) {
            otv = min(otv, dp[a1][i]);
            a1 = d[a1][i];
            f(a1, a2);
            break;
        }
    }
 
}
 
int main() {
    cin >> n;
    s = 1;
    s--;
    g.resize(n);
    gv.resize(n);
    used.resize(n, 0);
    vx.resize(n);
    vi.resize(n);
    pr.resize(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        g[a1].push_back(i + 1);
        g[i + 1].push_back(a1);
        gv[a1].push_back(a2);
        gv[i + 1].push_back(a2);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 50; j++) {
            d[i][j] = 0;
            dp[i][j] = 1000000000;
        }
    }
    dfs(s);
    for (int i = 1; i < n; i++) {
        d[i][0] = pr[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < 50; j++) {
            d[i][j] = d[d[i][j - 1]][j - 1];
            dp[i][j] = min(dp[i][j], min(dp[d[i][j - 1]][j - 1], dp[i][j - 1]));
        }
    }
    int k;
    cin >> k;
    for (int ii = 0; ii < k; ii++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        cur = 0;
        if ((vx[a1] < vx[a2]) && (vi[a1] > vi[a2])) {
            f(a2, a1);
            int a3 = ott;
            int ot1 = min(otv, dp[a3][0]);
            cout << ot1 << endl;
        } else {
            if ((vx[a1] > vx[a2]) && (vi[a1] < vi[a2])) {
                f(a1, a2);
                int a3 = ott;
                int ot1 = min(otv, dp[a3][0]);
                cout << ot1 << endl;
            } else {
                f(a1, a2);
                int a3 = ott;
                int ot1 = min(otv, dp[a3][0]);
                f(a2, a1);
                int a4 = ott;
                int ot2 = min(otv, dp[a4][0]);
                cout << min(ot1, ot2) << endl;
            }
        }
    }
}
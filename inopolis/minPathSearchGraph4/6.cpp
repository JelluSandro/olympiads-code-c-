#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    int INF = 1e18;
    int n;
    cin >> n;
    vector <vector<int>> a(n);
    vector <vector<int>> b(n);
    vector<int> r(n, INF);
    vector<int> c(n, 0);
    vector<int> pr(n, -1);
    vector<int> reb;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a1--;
        a2--;
        a[a1].push_back(a2);
        a[a2].push_back(a1);
        b[a1].push_back(a3);
        b[a2].push_back(a3);
    }
    int s = 1;
    s--;
    r[s] = 0;
    for (;;) {
        int mn = INF, my = -1;
        for (int i = 0; i < n; i++) {
            if (c[i] == 0) {
                if (r[i] < mn) {
                    mn = r[i];
                    my = i;
                }
            }
        }
        if (my == -1) {
            break;
        }
        // cout<<my<<" ";
        c[my] = 1;
        for (int i = 0; i < a[my].size(); i++) {
            if (c[a[my][i]] == 0) {
                if (r[a[my][i]] > r[my] + b[my][i]) {
                    r[a[my][i]] = min(r[a[my][i]], r[my] + b[my][i]);
                    pr[a[my][i]] = my;
                }
            }
        }
    }
    int ot = r[n - 1];
    int mx = ot;
    int u = n - 1;
    while (u != 0) {
        reb.push_back(u);
        u = pr[u];
    }
    reb.push_back(0);
    for (int ii = 0; ii < reb.size() - 1; ii++) {
        int zx = 0;
        int zn = 0;

        for (int i = 0; i < a[reb[ii]].size(); i++) {
            if (a[reb[ii]][i] == reb[ii + 1]) {
                b[reb[ii]][i] = b[reb[ii]][i] * 2;
                zx = i;
                break;
            }
        }
        for (int i = 0; i < a[reb[ii + 1]].size(); i++) {
            if (a[reb[ii + 1]][i] == reb[ii]) {
                //cout<<"LOL";
                b[reb[ii + 1]][i] = b[reb[ii + 1]][i] * 2;
                zn = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            r[i] = INF;
            c[i] = 0;
        }
        r[s] = 0;
        for (;;) {
            int mn = INF, my = -1;
            for (int i = 0; i < n; i++) {
                if (c[i] == 0) {
                    if (r[i] < mn) {
                        mn = r[i];
                        my = i;
                    }
                }
            }
            if (my == -1) {
                break;
            }
            c[my] = 1;
            for (int i = 0; i < a[my].size(); i++) {
                if (c[a[my][i]] == 0) {
                    r[a[my][i]] = min(r[a[my][i]], r[my] + b[my][i]);
                }
            }
        }
        // cout<<r[n-1]<< ' ';
        mx = max(mx, r[n - 1]);
        b[reb[ii]][zx] /= 2;
        b[reb[ii + 1]][zn] /= 2;
    }
    cout << mx - ot;
}

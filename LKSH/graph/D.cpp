#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    int INF = 1e12;
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
        if (pr[my] != -1) {
            reb.push_back(my);
            reb.push_back(pr[my]);
        }
        c[my] = 1;
        for (int i = 0; i < a[my].size(); i++) {
            if (c[a[my][i]] == 0) {
                if (r[a[my][i]] > b[my][i]) {
                    r[a[my][i]] = min(r[a[my][i]], b[my][i]);
                    pr[a[my][i]] = my;
                }
            }
        }
    }
    int ot = 0;
    for (int i = 0; i < n; i++) {
        ot += r[i];
    }
    int mx = INF;
    for (int ii = 0; ii < reb.size(); ii = ii + 2) {
        int zx = 0;
        int zn = 0;

        for (int i = 0; i < a[reb[ii]].size(); i++) {
            if (a[reb[ii]][i] == reb[ii + 1]) {
                b[reb[ii]][i] += INF;
                zx = i;
                break;
            }
        }
        for (int i = 0; i < a[reb[ii + 1]].size(); i++) {
            if (a[reb[ii + 1]][i] == reb[ii]) {
                b[reb[ii + 1]][i] += INF;
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
                    r[a[my][i]] = min(r[a[my][i]], b[my][i]);
                }
            }
        }
        int ot1 = 0;
        for (int i = 0; i < n; i++) {
            ot1 += r[i];
        }
        mx = min(mx, ot1);
        b[reb[ii]][zx] -= INF;
        b[reb[ii + 1]][zn] -= INF;
    }
    cout << ot << " " << mx;
}

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
    vector <vector<int>> ms(n);
    vector<int> r(n, INF);
    vector<int> c(n, 0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        a1--;
        a2--;
        a[a1].push_back(a2);
        a[a2].push_back(a1);
        b[a1].push_back(a3);
        b[a2].push_back(a3);
        ms[a1].push_back(a4);
        ms[a2].push_back(a4);
    }
    long long lt = 3e6;
    int rt = 1e11;
    for (int iii = 0; iii < 1000; iii++) {
        for (int i = 0; i < n; i++) {

            c[i] = 0;
            r[i] = INF;
        }
        int mt = (lt + rt) / 2;
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
                if (ms[my][i] >= mt)
                    if (c[a[my][i]] == 0) {
                        r[a[my][i]] = min(r[a[my][i]], r[my] + b[my][i]);
                    }
            }
        }
        if (r[n - 1] <= 1440) {
            lt = mt;
        } else {
            rt = mt;
        }
    }
    cout << ((lt - 3000000) / 100);
}

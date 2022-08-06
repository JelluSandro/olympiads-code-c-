#include <bits/stdc++.h>

#define int long long
using namespace std;
struct frimen {
    int x, y, z;
};

main() {
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    int INF = 1e18;
    int n;
    cin >> n;
    vector <frimen> a;
    vector<int> r(n, INF);
    vector<int> pr(n, -1);
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a1;
            cin >> a1;
            if (a1 != 1e5) {
                frimen xxx;
                xxx.x = i;
                xxx.y = j;
                xxx.z = a1;
                a.push_back(xxx);
                m++;
            }
        }
    }
    for (int iii = 0; iii < n; iii++) {
        if (r[iii] == INF) {
            r[iii] = 0;
            int v = -1;
            for (int ii = 0; ii < n; ii++) {
                v = -1;
                for (int i = 0; i < m; i++) {
                    if (r[a[i].y] > r[a[i].x] + a[i].z) {
                        r[a[i].y] = r[a[i].x] + a[i].z;
                        pr[a[i].y] = a[i].x;
                        v = a[i].y;
                    }
                }
            }
            if (v != -1) {
                for (int i = 0; i < n; i++) {
                    v = pr[v];
                }
                vector<int> path;
                for (int cur = v;; cur = pr[cur]) {
                    path.push_back(cur);
                    if (cur == v && path.size() > 1) break;
                }
                reverse(path.begin(), path.end());

                cout << "YES\n" << path.size() - 1 << endl;
                for (size_t i = 0; i < path.size() - 1; ++i)
                    cout << path[i] + 1 << ' ';
                return 0;
            }

        }
    }
    cout << "NO";
}

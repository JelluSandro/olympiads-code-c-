#include <bits/stdc++.h>

#define int long long
using namespace std;
struct frimen {
    int x, y, z;
};
int INF = 4e18;
int INFF = 5e18;
int n, m, s;
vector<int> used;
vector <vector<int>> graf;
vector<int> ot;

void dfs(int ver) {
    //  cout<<ver;
    used[ver] = 1;
    ot[ver] = -1;
    for (int i = 0; i < graf[ver].size(); i++) {
        // cout<<graf[ver][i]<<" "<<used[graf[ver][i]]<<" ";
        if (used[graf[ver][i]] == 0) {
            dfs(graf[ver][i]);
        }

    }
    // cout<<endl;
}

main() {
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    cin >> n >> m >> s;
    used.resize(n, 0);
    graf.resize(n);
    ot.resize(n, 0);
    vector <frimen> a;
    vector<int> r(n, INF);
    for (int i = 0; i < m; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a1--;
        a2--;
        graf[a1].push_back(a2);
        //   graf[a2].push_back(a1);
        frimen xxx;
        xxx.x = a1;
        xxx.y = a2;
        xxx.z = a3;
        a.push_back(xxx);

    }

    s--;
    r[s] = 0;

    for (int ii = 0; ii < n - 1; ii++) {
        for (int i = 0; i < m; i++) {
            if (r[a[i].x] < INF) {
                if (r[a[i].y] > r[a[i].x] + a[i].z) {
                    r[a[i].y] = max(r[a[i].x] + a[i].z, -INFF);
                }
            }
        }
    }
    vector<int> r1(n, INF);
    for (int i = 0; i < n; i++) {
        r1[i] = r[i];
    }
//for(int iii=0;iii<n;iii++)
    for (int i = 0; i < m; i++) {
        if (r1[a[i].x] < INF) {
            if (r1[a[i].y] > r1[a[i].x] + a[i].z) {
                r1[a[i].y] = max(r1[a[i].x] + a[i].z, -INFF);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (r1[i] != r[i]) {
            r[i] = -INF;
            if (used[i] == 0) {

                dfs[i];
            }
        }
        if (r[i] <= -INF) {
            r[i] = -INF;
            if (used[i] == 0) {
                //cout<<i<<" ";

                dfs(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (r[i] == INF) {
            cout << "*\n";
        } else {
            if (r[i] <= -INF) {
                cout << "-\n";
            } else {
                if (ot[i] == -1) {
                    cout << "-\n";
                } else
                    cout << r[i] << endl;
            }
        }

    }
}

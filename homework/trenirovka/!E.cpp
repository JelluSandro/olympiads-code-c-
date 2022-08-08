#include <bits/stdc++.h>

using namespace std;
#define int long long
int INF = 1e18;
int n, m;
int s, f;
vector <vector<int>> a;
vector <vector<int>> b;
vector<int> r;
vector<int> c;
int pa, pb;

main() {
    cin >> n >> m;
    cin >> s >> f;
    s--;
    f--;
    a.resize(n);
    b.resize(n);
    r.resize(n, INF);
    c.resize(n, 0);
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
    cin >> pa >> pb;
    set <pair<int, int>> q;
    q.insert({0, s});
    r[s] = 0;
    while (q.size() > 0) {
        pair<int, int> qq = *q.begin();
        int v = qq.second;
        int mn = qq.first;
        r[v] = mn;
        q.erase(q.begin());


        c[v] = 2;
        for (int i = 0; i < a[v].size(); i++) {
            if (c[a[v][i]] == 0) {
                if (b[v][i] <= pa) {
                    if (mn + b[v][i] < r[a[v][i]]) {
                        q.erase({r[a[v][i]], a[v][i]});
                        r[a[v][i]] = mn + b[v][i];
                        q.insert({mn + b[v][i], a[v][i]});
                    }
                }
            }

        }

    }
    //cout<<r[f];
    set <pair<int, int>> qv;
    for (int i = 0; i < n; i++) {
        //	cout<<r[i]<<" "<<i<<endl;
        qv.insert({r[i], i});
        c[i] = 0;
    }
    while (qv.size() > 0) {
        pair<int, int> qq = *qv.begin();
        int v = qq.second;
        int mn = qq.first;
        r[v] = mn;
        qv.erase(qv.begin());
        c[v] = 2;
        for (int i = 0; i < a[v].size(); i++) {
            if (c[a[v][i]] == 0) {
                if (b[v][i] >= pb) {
                    if (mn + b[v][i] < r[a[v][i]]) {
                        qv.erase({r[a[v][i]], a[v][i]});
                        r[a[v][i]] = mn + b[v][i];
                        qv.insert({mn + b[v][i], a[v][i]});
                    }
                }
            }

        }

    }
    if (r[f] == INF) {
        cout << -1;
    } else {
        cout << r[f];
    }
}


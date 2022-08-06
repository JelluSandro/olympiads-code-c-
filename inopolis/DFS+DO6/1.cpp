#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, m, s;
vector <vector<int>> g;
vector<int> b;
vector<int> c;
vector<int> d;
vector<int> ob;
vector<int> gb;
vector<int> used;
int ot = -1, otl, otr;

void dfs(int v, int ves) {
    b.push_back(ves);
    ob.push_back(v);
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i], ves + 1);
            b.push_back(ves);
            ob.push_back(v);
        }
    }

}

pair<int, int> mn(int v, int tl, int tr, int l, int r) {
    // cout<<v<<" "<<l<<" "<<r<<" "<<tl<<" "<<tr<<endl;
    if (l <= r) {
        if (l == tl && r == tr) {
            return (make_pair(c[v], d[v]));
        }
        int tm = (tl + tr) / 2;
        pair<int, int> a1 = mn(v * 2, tl, tm, l, min(r, tm));
        pair<int, int> a2 = mn(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        if (a1.first > a2.first) {
            return (a2);
        } else {
            return (a1);
        }
    }
    return (make_pair(1e18, 0));
}

void buildm(int v, int l, int r) {
    if (l == r) {
        c[v] = b[l];
        d[v] = l;
    } else {
        buildm(2 * v, l, (l + r) / 2);
        buildm(2 * v + 1, (l + r) / 2 + 1, r);
        if (c[2 * v] < c[2 * v + 1]) {
            d[v] = d[2 * v];
        } else {
            d[v] = d[2 * v + 1];
        }
        c[v] = min(c[2 * v], c[2 * v + 1]);
    }
}

main() {
    // freopen("feelgood.in","r",stdin);
    // freopen("feelgood.out","w",stdout);
    cin >> n;
    m = n - 1;
    s = 1;
    s--;
    g.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1;
        a1--;
        g[i + 1].push_back(a1);
        g[a1].push_back(i + 1);
    }
    dfs(s, 0);
    for (int i = 0; i < n; i++) {
        used[i] = 0;

    }
    gb.resize(n);
    //cout<<"LL";
    for (int i = 0; i < ob.size(); i++) {
        //cout<<ob[i]<<" ";
        if (used[ob[i]] == 0) {
            gb[ob[i]] = i;
        }
    }
    // cout<<"LL";
    c.resize(b.size() * 4);
    d.resize(b.size() * 4);
    // cout<<"LOL";
    buildm(1, 0, b.size() - 1);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {

        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        if (gb[a1] > gb[a2])
            swap(a1, a2);
        //  cout<<gb[a1]<<" "<<gb[a2];
        cout << ob[mn(1, 0, b.size() - 1, gb[a1], gb[a2]).second] + 1 << endl;
    }
}

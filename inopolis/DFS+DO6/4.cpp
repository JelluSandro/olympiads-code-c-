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
vector<int> cvet;
vector<int> cpr;
vector<int> ot;
vector<int> vic;
int cf = 0;

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

void dfs1(int v) {
    ///cout<<v<< ' ';
    used[v] = 1;

    if (cpr[cvet[v]] != -1) {

        int a1 = v, a2 = cpr[cvet[v]];
        if (gb[a1] > gb[a2])
            swap(a1, a2);
        //  cout<<ob[mn(1,0,b.size()-1,gb[a1],gb[a2]).second];
        vic[ob[mn(1, 0, b.size() - 1, gb[a1], gb[a2]).second]]--;
    }
    // cout<<cvet[v];
    cpr[cvet[v]] = v;
    for (int i = 0; i < g[v].size(); i++) {
        // cout<<" "<<g[v][i]<<" ";
        if (used[g[v][i]] == 0) {
            dfs1(g[v][i]);

            ot[v] += ot[g[v][i]];
        }
    }

}

void dfs2(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == 0) {
            dfs2(g[v][i]);
            vic[v] += vic[g[v][i]];
        }
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
    cvet.resize(n, 0);
    cpr.resize(n, -1);
    ot.resize(n, 1);
    vic.resize(n, 0);
    for (int i = 0; i <= m; i++) {
        //cout<<i;
        int a1, a2;
        cin >> a1 >> a2;
        // cout<<a1<< " ";
        a1--;
        a2--;
        if (a1 == -1) {
            s = i;
            cvet[i] = a2;
        } else {
            g[i].push_back(a1);
            g[a1].push_back(i);
            cvet[i] = a2;
        }
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
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    dfs1(s);
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    dfs2(s);
    for (int i = 0; i < n; i++) {

        cout << ot[i] + vic[i] << " ";
    }
}

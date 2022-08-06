#include <bits/stdc++.h>

#define int long long
using namespace std;
int n;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
int ot = -1, otl, otr;

void build(int v, int l, int r) {
    if (l == r) {
        a[v] = b[l];
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        a[v] = a[2 * v] + a[2 * v + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return a[v];
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm))
           + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

pair<int, int> mn(int v, int tl, int tr, int l, int r) {
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

void pr(int l, int r) {
    // cout<<l<<" "<<r<<endl;
    if (l > r) {
        return;
    }
    if (l == r) {

        int gg = b[l] * b[l];
        if (ot < gg) {
            ot = gg;
            otl = l;
            otr = r;
        }
    } else {
        pair<int, int> gg = mn(1, 0, n - 1, l, r);
        int g = sum(1, 0, n - 1, l, r) * gg.first;
        if (ot < g) {
            ot = g;
            otl = l;
            otr = r;
        }
        pr(l, gg.second - 1);
        pr(gg.second + 1, r);
    }
}

main() {
    freopen("feelgood.in", "r", stdin);
    freopen("feelgood.out", "w", stdout);
    cin >> n;
    a.resize(4 * n);
    c.resize(4 * n);
    d.resize(4 * n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    build(1, 0, n - 1);
    buildm(1, 0, n - 1);
    pr(0, n - 1);
    cout << ot << endl;
    cout << otl + 1 << " " << otr + 1;
}

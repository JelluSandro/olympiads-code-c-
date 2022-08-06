#include <bits/stdc++.h>

#define int long long
using namespace std;
int n;
vector<int> a;
vector<int> b;

void build(int v, int l, int r) {
    if (l == r) {
        a[v] = b[l];
        if (l % 2 == 1) {
            a[v] = -b[l];
        }
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        a[v] = a[2 * v] + a[2 * v + 1];
    }
}

void rebuild(int v, int pos, int l, int r) {
    if (l == r) {
        a[v] = b[l];
        if (l % 2 == 1) {
            a[v] = -b[l];
        }
    } else {
        if (pos <= (l + r) / 2) {
            rebuild(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuild(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
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

main() {
    freopen("signchange.in", "r", stdin);
    freopen("signchange.out", "w", stdout);
    cin >> n;
    a.resize(4 * n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    build(1, 0, n - 1);
    int ggg;
    cin >> ggg;
    int s;
    while (cin >> s) {
        if (s == 1) {
            int c, d;
            cin >> c >> d;
            c--;
            d--;
            int ot = sum(1, 0, n - 1, c, d);
            if (c % 2 == 1) {
                ot *= -1;
            }
            cout << ot << endl;
        }
        if (s == 0) {
            int c, d;
            cin >> c >> d;
            c--;
            b[c] = d;
            rebuild(1, c, 0, n - 1);
        }
    }
}

#include <bits/stdc++.h>

_Pragma("GCC optimize(\"-0fast\")")

using namespace std;
int const nn = 2e5 + 228;
int INF = 1e9;
int tree[4 * nn];
int mass[nn];

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = mass[l] == 0 ? 1 : 0;
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        tree[v] = (tree[2 * v] + tree[2 * v + 1]);
    }
}

void rebuild(int v, int pos, int l, int r) {
    if (l == r) {
        tree[v] = mass[l] == 0 ? 1 : 0;
    } else {
        if (pos <= (l + r) / 2) {
            rebuild(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuild(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
        tree[v] = (tree[2 * v] + tree[2 * v + 1]);
    }
}

int ask(int v, int tl, int tr, int l, int r) {
    /*if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return (ask(v * 2, tl, tm, l, min(r, tm)) + ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));*/
    if (r < tl || tr < l)
        return 0;
    if (l <= tl && tr <= r)
        return tree[v];
    int tm = (tl + tr) / 2;
    return ask(2 * v, tl, tm, l, r) + ask(2 * v + 1, tm + 1, tr, l, r);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("kthzero.in", "r", stdin);
    freopen("kthzero.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mass[i];
    }
    build(1, 0, n - 1);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        char a1;
        cin >> a1;
        if (a1 == 'u') {
            int l, r;
            cin >> l >> r;
            l--;
            mass[l] = r;
            rebuild(1, l, 0, n - 1);
        } else {
            int tl, tr, c;
            cin >> tl >> tr >> c;
            tl--;
            tr--;
            int l = tl, r = tr;
            for (int j = 0; j < 25; j++) {
                int m = (l + r) / 2;
                int x = ask(1, 0, n - 1, tl, m);
                if (x < c) {
                    l = m;
                } else {
                    r = m;
                }
            }
            if (ask(1, 0, n - 1, tl, r) == c) {
                cout << r + 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}


9
1 2
1 3
2 4
2 5
3 6
3 7
6 8
6 9
10
? 4 5
? 5 6
? 8 7
! 6
? 8 7
? 4 5
? 4 7
? 5 9
! 2
? 4 3
0

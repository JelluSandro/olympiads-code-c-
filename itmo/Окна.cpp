#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n = 2000020;
int a[2000020 * 4];
int ax[2000020 * 4];
int cr[2000020 * 4];
 
struct Sqre {
    int x1, y1, y2;
    bool flag;
 
    Sqre() {
        x1 = 0;
        y1 = 0;
        y2 = 0;
        flag = false;
    }
 
    Sqre(int _x1, int _y1, int _y2, bool _f) {
        flag = _f;
        x1 = _x1;
        y1 = _y1;
        y2 = _y2;
    }
};
 
bool cmp(Sqre aa, Sqre bb) {
    if (aa.x1 < bb.x1) {
        return true;
    } else if (aa.x1 == bb.x1) {
        if (aa.flag != bb.flag) {
            return aa.flag;
        }
    }
    return false;
}
 
void push(int v) {
    if (cr[v] != 0) {
        a[2 * v] += cr[v];
        a[2 * v + 1] += cr[v];
        cr[2 * v] += cr[v];
        cr[2 * v + 1] += cr[v];
        cr[v] = 0;
    }
}
 
void rebuild(int v, int pos, int l, int r, int zv) {
    if (v != zv) {
        if (pos <= (l + r) / 2) {
            rebuild(2 * v, pos, l, (l + r) / 2, zv);
        } else {
            rebuild(2 * v + 1, pos, (l + r) / 2 + 1, r, zv);
        }
        if (a[2 * v] > a[2 * v + 1]) {
            a[v] = a[2 * v];
            ax[v] = ax[2 * v];
        } else {
            a[v] = a[2 * v + 1];
            ax[v] = ax[2 * v + 1];
        }
    }
}
 
void build(int v, int l, int r) {
    if (l == r) {
        ax[v] = l;
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        if (a[2 * v] >= a[2 * v + 1]) {
            a[v] = a[2 * v];
            ax[v] = ax[2 * v];
        } else {
            a[v] = a[2 * v + 1];
            ax[v] = ax[2 * v + 1];
        }
    }
}
 
void pr(int v, int tl, int tr, int l, int r, int zn) {
    if (l > r)
        return;
    if (tl == tr) {
        a[v] += zn;
        rebuild(1, l, 0, n - 1, v);
        return;
    }
    push(v);
    if (l == tl && r == tr) {
        a[v] += zn;
        cr[v] = zn;
        rebuild(1, l, 0, n - 1, v);
        return;
    }
    int tm = (tl + tr) / 2;
    pr(v * 2, tl, tm, l, min(r, tm), zn);
    pr(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, zn);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 4 * n; i++) {
        a[i] = 0;
        cr[i] = 0;
        ax[i] = 0;
    }
    build(1, 0, n - 1);
    int m;
    cin >> m;
    vector<Sqre> b(2 * m);
    for (int j = 0; j < m; j++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 += 1000010;
        x2 += 1;
        y2 += 1000010;
        Sqre xx(x1, y1, y2, false);
        Sqre yy(x2, y1, y2, true);
        b[2 * j] = xx;
        b[2 * j + 1] = yy;
    }
    sort(b.begin(), b.end(), cmp);
    int mx = 0;
    int ansy = 0, ansx = 0;
    for (int i = 0; i < 2 * m; i++) {
        if (b[i].flag) {
            pr(1, 0, n - 1, b[i].y1, b[i].y2, -1);
        } else {
            pr(1, 0, n - 1, b[i].y1, b[i].y2, 1);
            if (mx < a[1]) {
                mx = a[1];
                ansy = ax[1] - 1000010;
                ansx = b[i].x1;
            }
        }
    }
    cout << mx << "\n";
    cout << ansx << " " << ansy;
}
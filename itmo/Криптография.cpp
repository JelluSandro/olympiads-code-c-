#include <bits/stdc++.h>
 
using namespace std;
 
 
 
struct mat {
    int a11, a12, a21, a22;
};
int r;
 
mat mul(mat a, mat b) {
    mat ans;
    ans.a11 = (a.a11 * b.a11 + a.a12 * b.a21) % r;
    ans.a12 = (a.a11 * b.a12 + a.a12 * b.a22) % r;
    ans.a21 = (a.a21 * b.a11 + a.a22 * b.a21) % r;
    ans.a22 = (a.a21 * b.a12 + a.a22 * b.a22) % r;
    return ans;
}
 
int n = 500011;
mat a[500011 * 4];
mat b[500011];
int mx = 1e9;
mat en;
 
void build(int v, int l, int r) {
    if (l == r) {
        a[v] = b[l];
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        a[v] = mul(a[2 * v], a[2 * v + 1]);
    }
}
 
void rebuild(int v, int pos, int l, int r) {
    if (l == r) {
        a[v] = b[l];
    } else {
        if (pos <= (l + r) / 2) {
            rebuild(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuild(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
        a[v] = mul(a[2 * v], a[2 * v + 1]);
    }
}
 
mat mn(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return en;
    if (tl == tr) {
        return a[v];
    }
    if (l == tl && r == tr)
        return a[v];
    int tm = (tl + tr) / 2;
    return mul(mn(v * 2, tl, tm, l, min(r, tm)),
               mn(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
 
 
int main() {
    en.a11 = 1;
    en.a22 = 1;
    en.a12 = 0;
    en.a21 = 0;
    int m;
    cin >> r >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> b[i].a11 >> b[i].a12 >> b[i].a21 >> b[i].a22;
    }
    build(1, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        mat ans = mn(1, 0, n - 1, c, d);
        cout << ans.a11 << ' ' << ans.a12 << "\n";
        cout << ans.a21 << " " << ans.a22 << "\n";
    }
}
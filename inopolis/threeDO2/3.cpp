#include <bits/stdc++.h>

using namespace std;
int n;
vector<long long> a;
vector<long long> cr1;
vector<long long> cr2;
vector<long long> b;
long long cons = 1000000000000000002;

void push(int v) {
    if (cr1[v] != -cons) {
        cr1[2 * v] = cr1[v];
        cr1[2 * v + 1] = cr1[v];
        a[2 * v] = cr1[v];
        a[2 * v + 1] = cr1[v];
        cr1[v] = -cons;
        cr2[2 * v] = -cons;
        cr2[2 * v + 1] = -cons;
    }
    if (cr2[v] != -cons) {
        if (cr2[2 * v] != -cons)
            cr2[2 * v] += cr2[v];
        else
            cr2[2 * v] = cr2[v];
        if (cr2[2 * v + 1] != -cons)
            cr2[2 * v + 1] += cr2[v];
        else
            cr2[2 * v + 1] = cr2[v];
        a[2 * v] += cr2[v];
        a[2 * v + 1] += cr2[v];
        cr2[v] = -cons;
    }
}

void rebuild(int v, int pos, int l, int r, int zv) {
    if (v != zv) {
        if (pos <= (l + r) / 2) {
            rebuild(2 * v, pos, l, (l + r) / 2, zv);
        } else {
            rebuild(2 * v + 1, pos, (l + r) / 2 + 1, r, zv);
        }
        a[v] = min(a[2 * v], a[2 * v + 1]);
    }
}

void pr(int v, int tl, int tr, int l, int r, long long zn, int cv) {
    if (l > r)
        return;
    if (tl == tr) {
        if (cv == 0) {
            a[v] = zn;
        } else {
            a[v] += zn;
        }
        rebuild(1, l, 0, n - 1, v);
        return;
    }
    push(v);
    if (l == tl && r == tr) {
        if (cv == 0) {
            a[v] = zn;
            cr1[v] = zn;
        } else {
            a[v] += zn;
            cr2[v] = zn;
        }
        rebuild(1, l, 0, n - 1, v);
        return;
    }
    int tm = (tl + tr) / 2;
    pr(v * 2, tl, tm, l, min(r, tm), zn, cv);
    pr(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, zn, cv);
}

void build(int v, int l, int r) {
    if (l == r) {
        a[v] = b[l];
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        a[v] = min(a[2 * v], a[2 * v + 1]);
    }
}

long long mn(int v, int tl, int tr, int l, int r) {
    //cout<<v<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<endl;
    if (l > r)
        return cons;
    if (tl == tr) {
        return a[v];
    }
    push(v);
    if (l == tl && r == tr)
        return a[v];
    int tm = (tl + tr) / 2;
    return min(mn(v * 2, tl, tm, l, min(r, tm)),
               mn(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    cin >> n;
    a.resize(4 * n);
    cr1.resize(4 * n, -cons);
    cr2.resize(4 * n, -cons);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    build(1, 0, n - 1);
    string s;
    while (cin >> s) {
        if (s == "min") {
            int c, d;
            cin >> c >> d;
            c--;
            d--;
            cout << mn(1, 0, n - 1, c, d) << endl;
        }
        if (s == "set") {
            int c, d;
            long long a1;
            cin >> c >> d >> a1;
            c--;
            d--;
            b[c] = d;
            pr(1, 0, n - 1, c, d, a1, 0);
        }
        if (s == "add") {
            int c, d;
            long long a1;
            cin >> c >> d >> a1;
            c--;
            d--;
            b[c] = d;
            pr(1, 0, n - 1, c, d, a1, 1);

        }
    }
}

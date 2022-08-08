#include <bits/stdc++.h>
 
using namespace std;
 
int n = 100022;
int a[100022 * 4];
int b[100022];
int mx = -1e9;
 
void build(int v, int l, int r) {
    if (l == r) {
        a[v] = b[l];
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }
}
 
void rebuild(int v, int pos, int l, int r) {
    if (l == r) {
        a[v] = l;
    } else {
        if (pos <= (l + r) / 2) {
            rebuild(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuild(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }
}
 
int reans(int v, int pos, int l, int r) {
    if (l == r) {
        a[v] = mx;
        return l;
    } else {
        int ans;
        if (a[2 * v] >= pos) {
            ans = reans(2 * v, pos, l, (l + r) / 2);
        } else if (a[2 * v + 1] >= pos) {
            ans = reans(2 * v + 1, pos, (l + r) / 2 + 1, r);
        } else {
            return reans(1, 0, 0, n - 1);
        }
        a[v] = max(a[2 * v], a[2 * v + 1]);
        return ans;
    }
}
 
 
int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        b[i] = i;
    }
    build(1, 0, n - 1);
    string s;
    while (cin >> s) {
        if (s == "enter") {
            int c;
            cin >> c;
            c--;
            cout << reans(1, c, 0, n - 1) + 1 << endl;
        }
        if (s == "exit") {
            int c;
            cin >> c;
            c--;
            b[c] = c;
            rebuild(1, c, 0, n - 1);
        }
    }
}
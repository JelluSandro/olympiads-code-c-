#include <bits/stdc++.h>
 
using namespace std;
 
int n = (1 << 17);
vector<unsigned int> a[(1 << 17) * 4];
unsigned int b[(1 << 17)];
int mx = -1e9;
 
void build(int v, int l, int r) {
    if (l == r) {
        a[v].push_back(b[l]);
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        merge(a[2 * v].begin(), a[2 * v].end(), a[2 * v + 1].begin(), a[2 * v + 1].end(), back_inserter(a[v]));
    }
}
 
unsigned int x;
unsigned int y;
unsigned int mn(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (tl == tr) {
        if (x <= a[v][0] && a[v][0] <= y) {
            return 1;
        }
        return 0;
    }
    if (l == tl && r == tr) {
        return upper_bound(a[v].begin(), a[v].end(), y) - lower_bound(a[v].begin(), a[v].end(), x);
    }
    int tm = (tl + tr) / 2;
    return (mn(v * 2, tl, tm, l, min(r, tm)) +
               mn(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
 
unsigned int aa, bb;
unsigned int cur = 0;
 
unsigned int nextRand17() {
    cur = cur * aa + bb;
    return cur >> 15;
}
 
unsigned int nextRand24() {
    cur = cur * aa + bb;
    return cur >> 8;
}
 
int main() {
    int q;
    cin >> q >> aa >> bb;
    for (int i = 0; i < (1 << 17); i++) {
        b[i] = nextRand24();
    }
    unsigned int ans = 0;
    build(1, 0, n - 1);
    for (int i = 0; i < q; i++) {
        unsigned int l = nextRand17();
        unsigned int r = nextRand17();
        if (l > r) swap(l, r);
        x = nextRand24();
        y = nextRand24();
        if (x > y) swap(x, y);
        unsigned xx = mn(1, 0, n - 1, l, r);
        bb += xx;
        ans += xx;
    }
    cout << ans;
}
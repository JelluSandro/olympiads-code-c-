#include <bits/stdc++.h>
 
using namespace std;
 
int n = 16777217;
uint32_t a[16777217];
unsigned int aa, bb;
unsigned int cur = 0;
 
unsigned int nextRand() {
    cur = cur * aa + bb;
    return cur >> 8;
}
 
 
int main() {
    int nn, mm;
    cin >> nn >> mm >> aa >> bb;
    for (int i = 0; i < 16777217; ++i) {
        a[i] = 0;
    }
    for (int i = 0; i < nn; ++i) {
        unsigned int ad = nextRand();
        unsigned int l = nextRand();
        unsigned int r = nextRand();
        if (l > r) swap(l, r);
        a[l] += ad;
        a[r + 1] -= ad;
        //pr(1, 0, n - 1, l, r, ad);
    }
    uint32_t cnt = 0;
    for (int i = 0; i < 16777217; i++) {
        cnt = (cnt + a[i]);
        if (i != 0) {
            a[i] = a[i - 1] + cnt;
        }
    }
    uint32_t ans = 0;
    for (int i = 0; i < nn; ++i) {
        unsigned int l = nextRand();
        unsigned int r = nextRand();
        if (l > r) swap(l, r);
        uint32_t xx = a[r];
        if (l != 0) {
            xx -= a[l - 1];
        }
        ans += xx;
        //ans += sum(1, 0, n - 1, l, r);
    }
    cout << ans;
}
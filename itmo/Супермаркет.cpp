#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
vector < ll > arr;
void q(int l, int r) {
    if (l >= r) {
        return;
    }
    ll x = arr[l + (r - l) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (i < r) {
        q(i, r);
    }
    if (j > l) {
        q(l, j);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    arr.resize(m);
    vector < ll > a(m), b(m), t(m);
    ll oo = 1e18 + 7;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> t[i];
        if (a[i] == 0) {
            oo = min(oo, b[i] + t[i]);
        }
    }
    int n, p;
    cin >> n >> p;
    if (p == 0) {
        cout << 0;
        return 0;
    }
    ll l = 0, r = 1e13 + 7;
    while (r - l > 1) {
        ll mm = l + (r - l) / 2;
        ll x = 0;
        for (int i = 0; i < m; i++) {
            if (a[i] == 0) {
                continue;
            }
            arr[i] = max(0LL, (mm - t[i] - b[i]) / a[i]);
        }
        q(0, m - 1);
        for (int i = 0; i < min(n, m); i++) {
            x += arr[m - 1 - i];
        }
        if (x < p) {
            l = mm;
        } else {
            r = mm;
        }
    }
    cout << min(r, oo);
}
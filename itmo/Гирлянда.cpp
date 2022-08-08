#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ld long double
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector < ld > a(n);
    cin >> a[0];
    ld l = 0, r = 1111;
    ld res = 0;
    for(int ii = 0; ii < 11111; ii++) {
        ld m = l + (r - l) / 2;
        a[1] = m;
        bool flag = 0;
        for(int i = 2; i < n; i++) {
            a[i] = 2 * a[i - 1] - a[i - 2] + 2;
            if (a[i] <= 0) {
                flag = 1;
            }
        }
        if (flag) {
            l = m;
        } else {
            r = m;
            res = a[n - 1];
        }
    }
    cout << fixed << setprecision(2) << res;
}
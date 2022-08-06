#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    freopen("forest.in", "r", stdin);
    freopen("forest.out", "w", stdout);
    int vp, vf;
    cin >> vp >> vf;
    long double g;
    cin >> g;
    long double l = 0, r = 1;
    long double a1 = 1 - g, a2 = g;
    for (int ii = 0; ii < 500; ii++) {
        long double m1 = l + (r - l) / 3;
        long double m2 = r - (r - l) / 3;
        long double r1 = (sqrt(a1 * a1 + m1 * m1)) / vp;
        long double r2 = (sqrt(a2 * a2 + (1 - m1) * (1 - m1))) / vf;
        long double r3 = (sqrt(a1 * a1 + m2 * m2)) / vp;
        long double r4 = (sqrt(a2 * a2 + (1 - m2) * (1 - m2))) / vf;
        if (r1 + r2 < r3 + r4) {
            r = m2;
        } else {
            l = m1;
        }
    }
    cout << l;
}

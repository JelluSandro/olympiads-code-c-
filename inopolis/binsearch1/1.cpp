#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    int n;
    cin >> n;
    long double h0;
    cin >> h0;
    long double l = 0, r = h0;
    for (int ii = 0; ii < 500; ii++) {
        long double m1 = (l + r) / 2;
        // cout<<m1<<endl;
        long double a[n];
        a[0] = h0;
        a[1] = m1;
        for (int i = 2; i < n; i++) {
            a[i] = a[i - 1] * 2 + 2 - a[i - 2];
        }
        bool f = 0;
        for (int i = 0; i < n; i++) {

            if (a[i] <= 0) {
                f = 1;
            }
        }


        if (f == 1) {
            l = m1;
        } else {
            r = m1;
        }
    }
    long double a[n];
    a[0] = h0;
    a[1] = l;

    for (int i = 2; i < n; i++) {
        a[i] = a[i - 1] * 2 + 2 - a[i - 2];

    }
    cout << fixed << setprecision(2) << a[n - 1];

}

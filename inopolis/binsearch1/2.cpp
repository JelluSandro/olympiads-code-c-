#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    int n;
    cin >> n;
    long double a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long double l = -1e8, r = 1e8;
    long double ot = 0;
    for (int ii = 0; ii < 100; ii++) {

        long double m1 = l + (r - l) / 3;
        long double m2 = r - (r - l) / 3;
        long double b1[n];
        long double b2[n];
        for (int i = 0; i < n; i++) {
            b1[i] = a[i] - m1;
            b2[i] = a[i] - m2;
        }
        long double ot1 = 0, pl1 = 0;
        long double ot2 = 0, pl2 = 0;
        for (int i = 0; i < n; i++) {
            pl2 += b1[i];
            if (pl2 < 0) {
                pl2 = 0;
            }
            pl1 = max(pl1, pl2);
        }
        for (int i = 0; i < n; i++) {
            ot2 += b1[i];
            if (ot2 > 0) {
                ot2 = 0;
            }
            ot1 = min(ot1, ot2);
        }
        long double s1 = max(pl1, abs(ot1));
        long double ot11 = 0, pl11 = 0;
        long double ot12 = 0, pl12 = 0;
        for (int i = 0; i < n; i++) {
            pl12 += b2[i];
            if (pl12 < 0) {
                pl12 = 0;
            }
            pl11 = max(pl11, pl12);
        }
        for (int i = 0; i < n; i++) {
            ot12 += b2[i];
            if (ot12 > 0) {
                ot12 = 0;
            }
            ot11 = min(ot11, ot12);
        }
        long double s2 = max(pl11, abs(ot11));
        ot = s1;
        //cout<<ot<<" "<<l<<" "<<r<<endl;
        if (s1 < s2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    cout << fixed << setprecision(6) << ot;
}

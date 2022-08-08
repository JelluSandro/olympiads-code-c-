#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
 
int main() {
    ll x, m;
    cin >> x >> m;
    cout << "? 1" << endl;
    ll k;
    cin >> k;
    if (k == x) {
        cout << "! 1" << endl;
        return 0;
    }
    ll pos = x - k + 1;
    if (x > k) {
        ll l = max(pos - 501LL, 1LL), r = min(pos, (long long)1e18 - m) + 1;
        for (int ii = 0; ii < 9; ii++) {
            ll mm = min(l + (r - l) / 2, (long long)1e18 - m);
            cout << "? " << mm << endl;
            ll y;
            cin >> y;
            if (y == x) {
                cout << "! " << mm <<endl;
                return 0;
            }
            if (y > x) {
                r = mm;
            } else {
                l = mm;
            }
        }
        cout << "! -1" << endl;
        return 0;
    } else {
        pos = ((long long)1e18 - m) - k + x + 1;
        ll l = max(pos - 1, 1LL), r = min((long long)1e18 - m, pos + 501LL) + 1;
        for (int ii = 0; ii < 9; ii++) {
            ll mm = min(l + (r - l) / 2, (long long)1e18 - m);
            cout << "? " << mm << endl;
            ll y;
            cin >> y;
            if (y == x) {
                cout << "! " << mm <<endl;
                return 0;
            }
            if (y > x) {
                r = mm;
            } else {
                l = mm;
            }
        }
        cout << "! " << -1 <<endl;
        return 0;
    }
}
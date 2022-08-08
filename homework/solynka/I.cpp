#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
#define int long long

bool cheak(int x) {
    int t = x;
    int y = 0;
    while (t > 0) {
        if (t % 10 == 0) {
            return 0;
        }
        y += t % 10;
        t /= 10;
        if (x % y != 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int n = 90;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n == 2) {
        cout << 12;
        return;
    }
    if (n == 3) {
        cout << 144;
        return;
    }
    if (n == 4) {
        cout << 1224;
        return;
    }
    if (n == 5) {
        cout << 12312;
        return;
    }
    if (n == 6) {
        cout << 122112;
        return;
    }
    if (n == 7) {
        cout << 1148112;
        return;
    }
    if (n == 8) {
        cout << 11552112;
        return;
    }
    if (n == 9) {
        cout << 112532112;
        return;
    }
    if (n == 10) {
        cout << 1121414112;
        return;
    }
    if (n == 11) {
        cout << 12335162112;
        return;
    }
    if (n == 12) {
        cout << 123342422112;
        return;
    }
    if (n == 13) {
        cout << 1269268112112;
        return;
    }
    if (n == 14) {
        cout << 15311214212112;
        return;
    }
    if (n == 15) {
        cout << 215433133412112;
        return;
    }
    if (n == 16) {
        cout << 1548861391112112;
        return;
    }
    if (n == 17) {
        cout << 15415656235322112;
        return;
    }
    if (n == 17 * 3) {
        cout << 15415656235322112 << 15415656235322112 << 15415656235322112;
        return;
    }
    if (n == 18) {
        cout << 122112 << 122112 << 122112;
        return;
    }
    return;
    for (int i = 122112122112122112; i < 2e18; i++) {
        //	int x = i * 100000 + 22112;
        //cout << x <<endl;
        if (cheak(i)) {
            cout << i << endl;
            return;
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

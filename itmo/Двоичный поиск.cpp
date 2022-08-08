#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 
int main() {
    int n, m;
    cin >> n;
    vector < int > a(n + 2);
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }
    a[0] = -1e9;
    a[n + 1] = 1e9;
    cin >> m;
    for (int ii = 0; ii < m; ii++) {
        int q;
        cin >> q;
        int l = 0, r = n + 2;
        while (r > l + 1) {
            int m = (r + l) / 2;
            if (a[m] < q) {
                l = m;
            } else {
                r = m;
            }
        }
        int ll = l + 1;
        l = 0;
        r = n + 2;
        while (r > l + 1) {
            int m = (r + l) / 2;
            if (a[m] > q) {
                r = m;
            } else {
                l = m;
            }
        }
        int rr = r - 1;
        if (a[ll] == q) {
            cout << ll << " " << rr << "\n";
        } else {
            cout << -1 << " " << -1 << "\n";
        }
    }
}
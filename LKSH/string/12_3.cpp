#include <bits/stdc++.h>

#define int long long
using namespace std;
int p[(int) 2e5];
int p1[(int) 2e5];

main() {
    int mod = 1e9 + 7;
    string s;
    cin >> s;
    int n = s.size();
    p[0] = 1;
    p1[0] = 1;
    for (int i = 1; i < 2e5; i++) {
        p[i] = p[i - 1] * 31;
        p1[i] = (p1[i - 1] * 47) % mod;
    }
    int pr[n];
    int pr1[n];
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) {
            pr[i] = pr[i - 1] + (int) (s[i] - 'a' + 1) * p[i];
            pr1[i] = (pr1[i - 1] + ((int) (s[i] - 'a' + 1) * p1[i]) % mod) % mod;
        } else {
            pr[i] = (int) (s[i] - 'a' + 1) * p[i];
            pr1[i] = ((int) (s[i] - 'a' + 1) * p1[i]) % mod;
        }
    }
    int m;
    cin >> m;
    for (int ii = 0; ii < m; ii++) {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        a1--;
        a2--;
        a3--;
        a4--;
        if (a2 - a1 != a4 - a3) {
            cout << "No\n";
        } else {
            int x = pr[a2];
            int y = pr[a4];
            int x1 = pr1[a2];
            int y1 = pr1[a4];
            if (a1 - 1 >= 0) {
                x = x - pr[a1 - 1];
                x1 = ((x1 - pr1[a1 - 1]) % mod + mod) % mod;
            }
            if (a3 - 1 >= 0) {
                y -= pr[a3 - 1];
                y1 = ((y1 - pr1[a3 - 1]) % mod + mod) % mod;
            }
            if (a1 > a3) {
                y *= p[a1 - a3];
                y1 = (y1 * p1[a1 - a3]) % mod;
            } else {
                x *= p[a3 - a1];
                x1 = (x1 * p1[a3 - a1]) % mod;
            }
            if ((x == y) && (x1 == y1)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

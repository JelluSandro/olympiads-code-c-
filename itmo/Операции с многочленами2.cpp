#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
 
int md = 998244353;
 
int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
int f(int a) {
    int x, y, g = gcd(a, md, x, y);
    return (g != 1) ? 1 : (x % md + md) % md;
}
 
size_t mm;
 
vector<int> mul(vector<int> &p, vector<int> &q) {
    int mlsz = min(p.size() + q.size() - 1, mm + 1);
    vector<int> ml(mlsz, 0);
    for (int i = 0; i < mlsz; i++) {
        for (int j = 0; j < p.size(); j++) {
            if (j > i) {
                break;
            }
            int x = i - j;
            if (x < q.size()) {
                ml[i] = (ml[i] + (p[j] * q[x]) % md) % md;
            }
        }
    }
    return ml;
}
 
vector<vector<int> > pp;
 
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    mm = m;
    int mx = max(m, n) + 1;
    vector<int> p(mx);
    for (int i = 0; i < n + 1; i++) {
        cin >> p[i];
    }
    vector<int> e(mx, 0);
    e[0] = 1;
    pp.push_back(e);
    pp.push_back(p);
    for (int i = 2; i < m + 1; i++) {
        pp.push_back(mul(pp[i - 1], p));
    }
    vector<int> s(mx);
    s[0] = 1;
    for (int i = 1; i < m + 1; i++) {
        s[i] = ((((-s[i - 1] + md) % md)
                 * f((4 * i * i - 8 * i * i * i + md) % md)) % md
                * ((16 * i * i - 8 * i * i * i - 6 * i + md) % md)) % md;
    }
    for (int i = 0; i < m; i++) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            ans = (ans + (s[j] * pp[j][i] % md)) % md;
        }
        cout << ans << " ";
    }
    cout << "\n";
    vector<int> ee(m + 1, 0);
    ee[0] = 1;
    for (int i = 1; i < m + 1; i++) {
        ee[i] = (ee[i - 1] * f(i)) % md;
    }
    for (int i = 0; i < m; i++) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            ans = (ans + (ee[j] * pp[j][i]) % md) % md;
        }
        cout << ans << " ";
    }
    cout << "\n";
    vector<int> lg(m + 1, 0);
    lg[1] = 1;
    for (int i = 2; i < m + 1; i++) {
        lg[i] = (((((-lg[i - 1] + md) % md) * (i - 1)) % md) * f(i)) % md;
    }
    for (int i = 0; i < m; i++) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            ans = (ans + (lg[j] * pp[j][i]) % md) % md;
        }
        cout << ans << " ";
    }
}
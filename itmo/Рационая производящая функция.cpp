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
    int k;
    cin >> k;
    vector<int> a(k, 0), c(k, 0), p(k + 1, 0), q(k + 1, 0);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        p[i] = a[i];
    }
    q[0] = 1;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        q[i + 1] = -c[i];
        if (i != 0) {
            for (int j = 1; j < i + 1; j++) {
                p[i] += a[i - j] * q[j];
            }
        }
    }
    int x;
    for (int i = k - 1; i >= 0; i--) {
        if (p[i] != 0) {
            x = i;
            cout << i << "\n";
            break;
        }
    }
    for (int i = 0; i < x + 1; i++) {
        cout << p[i] << " ";
    }
    cout << "\n" << k << "\n";
    for (int i = 0; i < k + 1; i++) {
        cout << q[i] << " ";
    }
}
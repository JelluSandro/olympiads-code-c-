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
    md = 1e9 + 7;
    int k, m;
    cin >> k >> m;
    vector<int> c(k);
    set<int> st;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        st.insert(c[i]);
    }
    vector<int> t(m + 1, 0);
    vector<int> p(m + 1, 0);
    t[0] = 1;
    p[0] = 1;
    for (int i = 1; i < m + 1; i++) {
        int ans = 0;
        for (int j = 1; j < i + 1; j++) {
            if (st.count(j) != 0) {
                //cout << p[i - j] << "\n";
                ans = (ans + p[i - j]) % md;
            }
        }
        t[i] = ans;
        cout << ans << " ";
        for (int j = 0; j < i + 1; j++) {
            //cout << p[i] << " " << t[j] << " " << t[i -j] << endl;
            p[i] = (p[i] + t[j] * t[i - j]) % md;
        }
    }
 
}
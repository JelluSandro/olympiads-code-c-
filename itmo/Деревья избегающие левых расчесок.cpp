#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
 
int md = 998244353;
 
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}
 
int gcd1(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd1(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
int f(int a) {
    int x, y, g = gcd1(a, md, x, y);
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
 
 
int ppow(int a, int n) {
    int c = 1;
    while (n > 0) {
        if ((n & 1) != 0) {
            c = (c * a) % md;
            n--;
        } else {
            a = (a * a) % md;
            n = n >> 1;
        }
    }
    return c;
}
 
vector<int> div(vector<int> &a, vector<int> &b) {
    //cout << b[0] << " !!!!" <<endl;
    vector<int> c(mm, 0);
    c[0] = (ppow(b[0], md - 2) * c[0]) % md;
    for (int i = 1; i < mm; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (i - j < b.size()) {
                cnt = (cnt + c[j] * b[i - j] % md) % md;
            }
        }
        if (i < a.size()) {
            c[i] = (a[i] - cnt + md) % md;
        } else {
            c[i] = (md - cnt) % md;
        }
        c[i] = (ppow(b[0], md - 2) * c[i]) % md;
    }
    return c;
}
 
vector<int> sm(vector<int> &a, vector<int> &b) {
    int mxsz = max(a.size(), b.size());
    vector<int> res(mxsz, 0);
    for (int i = 0; i < a.size(); i++) {
        res[i] = (res[i] + a[i]) % md;
    }
    for (int i = 0; i < b.size(); i++) {
        res[i] = (res[i] + b[i]) % md;
    }
    return res;
}
 
vector<int> factor(vector<int> &a) {
    vector<int> ans(a.size(), 0);
    for (int i = 1; i < a.size(); i++) {
        ans[i - 1] = a[i] * i;
    }
    return ans;
}
 
vector<int> pow(vector<int> a, int n) {
    vector<int> c(1, 1);
    while (n > 0) {
        if ((n & 1) != 0) {
            c = mul(c, a);
            n--;
        } else {
            a = mul(a, a);
            n = n >> 1;
        }
    }
    return c;
}
 
int k, n;
 
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    mm = max(k, n) + 1;
    vector<int> p{0, 1};
    vector<int> q(1, 1);
    for (int i = 3; i < k + 1; i++) {
        vector<int>pp = q;
        pp.insert(pp.begin(), 0);
        vector<int>x1(1, (md - 1));
        vector<int>x2 = mul(x1, p);
        vector<int> qq = sm(x2, q);
        q = qq;
        p = pp;
    }
    vector<int> ans = div(p, q);
    for (int i = 1; i < n + 1; i++) {
        cout << ans[i] << "\n";
    }
}
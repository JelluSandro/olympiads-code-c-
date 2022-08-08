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
 
struct fraction {
    int p, q;
 
    fraction(int p, int q) {
        int t = gcd(abs(p), abs(q));
        p /= t;
        q /= t;
        if (q < 0) {
            q *= -1;
            p *= -1;
        }
        this->p = p;
        this->q = q;
    }
 
    fraction operator+(const fraction &a) const {
        int x = a.q * (q / gcd(a.q, q));
        return {a.p * (x / a.q) + (x / q) * p, x};
    }
 
    fraction operator-(const fraction &a) const {
        return fraction(p, q) + fraction(-a.p, a.q);
    }
 
    fraction operator*(const fraction &a) const {
        int tt1 = gcd(p, a.q);
        int tt2 = gcd( a.p, q);
        int pp1 = p / tt1;
        int qq1 = a.q / tt1;
        int pp2 = a.p / tt2;
        int qq2 = q / tt2;
        return {pp1 * pp2, qq1 * qq2};
    }
 
    fraction operator/(const fraction &a) const {
        return fraction(p, q) * fraction(a.q, a.p);
    }
 
};
 
 
vector<fraction> mul(vector<fraction> &p, vector<fraction> &q) {
    int mlsz = min(p.size() + q.size() - 1, mm + 1);
    vector<fraction> ml(mlsz, fraction(0, 1));
    for (int i = 0; i < mlsz; i++) {
        for (int j = 0; j < p.size(); j++) {
            if (j > i) {
                break;
            }
            int x = i - j;
            if (x < q.size()) {
                ml[i] = (ml[i] + (p[j] * q[x]));
            }
        }
    }
    return ml;
}
 
vector<fraction> div(vector<fraction> const &a, vector<fraction> const &b) {
    vector<fraction> c(22, fraction(0, 1));
    c[0] = a[0] / b[0];
    for (int i = 1; i < 22; i++) {
        fraction cnt = fraction(0, 1);
        for (int j = 0; j < i; j++) {
            if (i - j < b.size()) {
                cnt = cnt + c[j] * b[i - j];
            }
        }
        if (i < a.size()) {
            c[i] = a[i] - cnt;
        } else {
            c[i] = fraction(0, 1) - cnt;
        }
        c[i] = c[i] / b[0];
    }
    return c;
}
 
vector<fraction> sm(vector<fraction> &a, vector<fraction> &b) {
    int mxsz = max(a.size(), b.size());
    vector<fraction> res(mxsz, fraction(0, 1));
    for (int i = 0; i < a.size(); i++) {
        res[i] = res[i] + a[i];
    }
    for (int i = 0; i < b.size(); i++) {
        res[i] = res[i] + b[i];
    }
    return res;
}
 
int r, k;
vector<int> p;
 
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    cin >> r >> k;
    mm = 2 * k + 2;
    p.resize(k + 1);
    for (int i = 0; i < k + 1; i++) {
        cin >> p[i];
    }
    int fac = 1;
    for (int i = 1; i <= k; i++) {
        fac *= i;
    }
    vector<fraction> res(1, fraction(0, 1));
    for (int i = 0; i < k + 1; i++) {
        vector<fraction> c(1, fraction(1, 1));
        for (int j = k; j > 0; j--) {
            vector<fraction> rr{fraction(j - i, 1), fraction(1, 1)};
            c = mul(c, rr);
        }
        vector<fraction> g(1, fraction(1, fac));
        c = mul(c, g);
        for (int j = 0; j < i; j++) {
            vector<fraction> gg(1, fraction(r, 1));
            c = div(c, gg);
        }
        vector<fraction> ff(1, fraction(p[i], 1));
        vector<fraction> ot = mul(c, ff);
        res = sm(res, ot);
    }
    for (int i = 0; i < k + 1; i++) {
        cout << res[i].p << "/" << res[i].q << " ";
    }
}
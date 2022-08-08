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
                ml[i] = (ml[i] + (p[j] * q[x]));
            }
        }
    }
    return ml;
}
 
vector<int> div(vector<int> &a, vector<int> &b) {
    vector<int> c(mm, 0);
    c[0] = a[0] / b[0];
    for (int i = 1; i < mm; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (i - j < b.size()) {
                cnt = cnt + c[j] * b[i - j];
            }
        }
        if (i < a.size()) {
            c[i] = a[i] - cnt;
        } else {
            c[i] = -cnt;
        }
        c[i] = c[i] / b[0];
    }
    return c;
}
 
vector<int> sm(vector<int> &a, vector<int> &b) {
    int mxsz = max(a.size(), b.size());
    vector<int> res(mxsz, 0);
    for (int i = 0; i < a.size(); i++) {
        res[i] = res[i] + a[i];
    }
    for (int i = 0; i < b.size(); i++) {
        res[i] = res[i] + b[i];
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
 
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    int r, d;
    cin >> r >> d;
    mm = 2 * d + 1;
    vector<int> fac(d + 1, 1);
    for (int i = 1; i < d + 1; i++) {
        fac[i] = fac[i - 1] * i;
    }
    vector<int> p(d + 1, 0);
    for (int i = 0; i < d + 1; i++) {
        cin >> p[i];
    }
    vector<int> res(1, r);
    vector<int> kk{1, -r};
    vector<vector<int>> pp;
    vector<vector<int>> qq;
    pp.emplace_back(1, 1);
    qq.push_back(kk);
    for (int i = 1; i < d + 1; i++) {
        vector<int> fac1 = factor(pp[i - 1]);
        vector<int> ml1 = mul(fac1, kk);
        vector<int> ml2 = mul(pp[i - 1], res);
        vector<int> x1 = vector<int>(1, i);
        vector<int> ml3 = mul(ml2, x1);
        vector<int> cnt = sm(ml1, ml3);
        vector<int> ans(1, 0);
        for (int j = 0; j < i; j++) {
            vector<int> x2(1, fac[i] / (fac[j] * fac[i - j]));
            vector<int> ml4 = mul(res, x2);
            vector<int> pow1 = pow(kk, i - j);
            vector<int> ml5 = mul(ml4, pow1);
            vector<int> ml6 = mul(ml5, pp[j]);
            /*for (int ii = 0; ii < ml6.size(); ii++) {
                cout << ml6 [ii] << " ";
            }
            cout << "\n";
             */
            ans = sm(ans, ml6);
        }
        //cout << "PES\n";
        vector<int> px1(1, -1);
        vector<int> px2 = mul(px1, ans);
        vector<int> px4 = sm(cnt, px2);
        vector<int> px5 = div(px4, res);
        pp.emplace_back(px5);
        vector<int> qqq = pow(kk, i + 1);
        qq.emplace_back(qqq);
    }
    /*
    for (int i = 0; i < pp.size(); i++) {
        for(int j =0; j < pp[i].size(); j++) {
            cout << pp[i][j] << " ";
        }
        cout << "\n";
    }
     */
    vector<int> pans(1, 0);
    vector<int> qans = pow(kk, d + 1);
    for (int i = 0; i < d + 1; i++) {
        vector<int> x1(1, p[i]);
        vector<int> x2 = pow(kk, d - i);
        vector<int> x3 = mul(x1, x2);
        vector<int> x4 = mul(x3, pp[i]);
        pans = sm(pans, x4);
    }
    int xx = pans.size() - 1;
    for (; xx > 0; xx--) {
        if (pans[xx] != 0)
            break;
    }
     cout << xx<< "\n";
    for (int i = 0; i < xx + 1; i++) {
         cout << pans[i] << " ";
    }
    cout << "\n";
 
    cout << qans.size() - 1 << "\n";
    for (int i = 0; i < qans.size(); i++) {
        cout << qans[i] << " ";
    }
    cout << "\n";
}
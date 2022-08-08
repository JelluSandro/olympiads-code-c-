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
    //cout << b[0] << " !!!!" <<endl;
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
 
vector<int> parse(string s) {
    //cout << s << endl;
    if (s[0] == 'B') {
        return vector<int>{0, 1};
    } else if (s[0] == 'P') {
        string t = "";
        int cnt = 0;
        vector<int> a, b;
        for (int j = 2; j < s.size(); j++) {
            if (s[j] == '(') {
                cnt++;
            } else if (s[j] == ')') {
                cnt--;
                if (cnt < 0) {
                    b = parse(t);
                    break;
                }
            } else if (s[j] == ',' && cnt == 0) {
                a = parse(t);
                t = "";
                continue;
            }
            t = t + s[j];
        }
        return mul(a, b);
    } else if (s[0] == 'L') {
        string t = "";
        int cnt = 0;
        vector<int> a;
        for (int j = 2; j < s.size(); j++) {
            if (s[j] == '(') {
                cnt++;
            } else if (s[j] == ')') {
                cnt--;
                if (cnt < 0) {
                    a = parse(t);
                    break;
                }
            }
            t = t + s[j];
        }
        a[0] = 0;
        vector<int> x1(1, 1), x2(1, -1);
        vector<int> x3 = mul(x2, a);
        vector<int> x4 = sm(x1, x3);
        vector<int> x5 = div(x1, x4);
        return x5;
    } else if (s[0] == 'S') {
        string t = "";
        int cnt = 0;
        vector<int> a;
        for (int j = 2; j < s.size(); j++) {
            if (s[j] == '(') {
                cnt++;
            } else if (s[j] == ')') {
                cnt--;
                if (cnt < 0) {
                    a = parse(t);
                    break;
                }
            }
            t = t + s[j];
        }
        vector<int> x1(1, 1);
        vector<int> ans = x1;
        for (int i = 1; i <= 7; i++) {
            vector<int> pp = pow(vector<int>{0, 1}, i);
            vector<int> x2(1, -1);
            vector<int> x3 = mul(x2, pp);
            vector<int> x4 = sm(x1, x3);
            int ppp = 0;
            if (i < a.size()) {
                ppp = a[i];
            }
            vector<int> x5 = pow(x4, ppp);
            vector<int> x6 = div(x1, x5);
            ans = mul(ans, x6);
        }
        return ans;
    }
    return vector<int>(1, 0);
}
 
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    mm = 7;
    string s;
    cin >> s;
    vector<int> x = parse(s);
    for (int i = 0; i < 7; i++) {
        if (i < x.size()) {
            cout << x[i] << " ";
        } else {
            cout << 0 << " ";
        }
    }
    //P(S(B),L(B))
    //L(P(L(L(L(P(P(P(B,L(B)),L(B)),P(B,L(B)))))),P(B,L(B))))
    //L(L(P(P(P(B,L(B)),L(B)),P(B,L(B)))))
}
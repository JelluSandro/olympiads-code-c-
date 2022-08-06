#include <bits/stdc++.h>

#define int long long
using namespace std;
string s;
int n;
int p[(int) 2e5];
vector<int> a;
vector<int> b;
vector<int> aa;
vector<int> bb;
int md = 1e9 + 7;

void build(int v, int l, int r) {
    if (l == r) {
        a[v] = b[l];
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        a[v] = (a[2 * v] + a[2 * v + 1]) % md;
    }
}

void rebuild(int v, int pos, int l, int r) {
    if (l == r) {
        a[v] = b[l];
    } else {
        if (pos <= (l + r) / 2) {
            rebuild(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuild(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
        a[v] = (a[2 * v] + a[2 * v + 1]) % md;
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return a[v];
    int tm = (tl + tr) / 2;
    return (sum(v * 2, tl, tm, l, min(r, tm))
            + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % md;
}

void build1(int v, int l, int r) {
    if (l == r) {
        aa[v] = bb[l];
    } else {
        build1(2 * v, l, (l + r) / 2);
        build1(2 * v + 1, (l + r) / 2 + 1, r);
        aa[v] = (aa[2 * v] + aa[2 * v + 1]) % md;
    }
}

void rebuild1(int v, int pos, int l, int r) {
    if (l == r) {
        aa[v] = bb[l];
    } else {
        if (pos <= (l + r) / 2) {
            rebuild1(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuild1(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
        aa[v] = (aa[2 * v] + aa[2 * v + 1]) % md;
    }
}

int sum1(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return aa[v];
    int tm = (tl + tr) / 2;
    return ((sum1(v * 2, tl, tm, l, min(r, tm))
             + sum1(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % md);
}

main() {
    //freopen("rsq.in","r",stdin);
    //freopen("rsq.out","w",stdout);
    cin >> s;
    n = s.size();
    a.resize(4 * n);
    b.resize(n);
    aa.resize(4 * n);
    bb.resize(n);
    p[0] = 1;
    for (int i = 1; i < 2e5; i++) {
        p[i] = (p[i - 1] * 31) % md;
    }
    for (int i = 0; i < n; i++) {
        b[i] = ((int) (s[i] - 'a' + 1) * p[i]) % md;
    }
    for (int i = n - 1; i >= 0; i--) {
        bb[n - i - 1] = ((int) (s[i] - 'a' + 1) * p[n - i - 1]) % md;
    }
    build(1, 0, n - 1);
    build1(1, 0, n - 1);
    int hh;
    cin >> hh;
    for (int ii = 0; ii < hh; ii++) {
        string tt;
        cin >> tt;
        if (tt == "change") {
            int a1;
            cin >> a1;
            a1--;
            char a2;
            cin >> a2;
            b[a1] = ((int) (a2 - 'a' + 1) * p[a1]) % md;
            bb[n - a1 - 1] = ((int) (a2 - 'a' + 1) * p[n - a1 - 1]) % md;
            rebuild(1, a1, 0, n - 1);
            rebuild1(1, n - a1 - 1, 0, n - 1);
        }
        if (tt == "palindrome?") {
            int a1, a2;
            cin >> a1 >> a2;
            a1--;
            a2--;
            int xx = sum(1, 0, n - 1, a1, a2);
            int yy = sum1(1, 0, n - 1, n - a2 - 1, n - a1 - 1);
            //cout<<xx<<" "<<yy<<endl;
            int a3 = a1;
            int a4 = n - a2 - 1;
            if (a3 > a4) {
                // cout<<a3-a4<<" "<<a3<<" "<<a4<<" "<<p[a3-a4]<<endl;
                yy = (yy * p[a3 - a4]) % md;
            } else {
                //  cout<<a4-a3<<" "<<a3<<" "<<a4<<" "<<p[a4-a3]<<endl;
                xx = (xx * p[a4 - a3]) % md;
            }
            if (xx == yy) {
                // cout<<xx<<" "<<yy;
                cout << "Yes\n";
            } else {
                //  cout<<xx<<" "<<yy;
                cout << "No\n";
            }
        }

    }
}

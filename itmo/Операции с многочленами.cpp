#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int32_t main() {
    int n, m;
    cin >> n >> m;
    int md = 998244353;
    vector<int> p(n + 1);
    vector<int> q(m + 1);
    for (int i = 0; i < n + 1; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m + 1; i++) {
        cin >> q[i];
    }
    int mxsz = max(q.size(), p.size());
    vector<int> sm(mxsz, 0);
    for (int i = 0; i < mxsz; i++) {
        if (i < q.size()) {
            sm[i] = (sm[i] + q[i]) % md;
        }
        if (i < p.size()) {
            sm[i] = (sm[i] + p[i]) % md;
        }
    }
    cout << mxsz - 1 << "\n";
    for (int i = 0; i < mxsz; i++) {
        cout << sm[i] << " ";
    }
    int mlsz = n + m + 1;
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
    cout << "\n" << mlsz - 1 << "\n";
    for (int i = 0; i < mlsz; i++) {
        cout << ml[i] << " ";
    }
    cout << "\n";
    vector<int> divq(1000 + 1, 0);
    divq[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        int x = 0;
        for (int j = 1; j <= i; j++) {
            if (j < q.size() && (i - j < i)) {
                x = (x + q[j] * divq[i - j] + md) % md;
            }
        }
        divq[i] = (-x + md) % md;
    }
    for (int i = 0; i < 1000; i++) {
        int ans = 0;
        for (int j = 0; j <= i; j++) {
            if (j < p.size()) {
                ans = (ans + p[j] * divq[i - j]) % md;
            }
        }
        cout << ans << " ";
    }
}
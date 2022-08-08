#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
vector < int > pr, rn, r, w;
int p = 1e6 + 3;
long long z = 0;
pair < int, int > find_set(int v) {
    if (v == pr[v]) {
        return {v, r[v]};
    }
    pair < int, int > xx = find_set(pr[v]);
    return {xx.first, xx.second + r[v]};
}
void union_sets(int a, int b) {
    if (a != b) {
        if (rn[a] < rn[b]) {
            swap(a, b);
        }
        pr[b] = a;
        if (rn[a] == rn[b]) {
            ++rn[a];
        }
    }
}
main() {
    int n, m;
    cin >> n >> m;
    pr.resize(2 * n, 0);
    rn.resize(2 * n, 0);
    r.resize(2 * n, 0);
    w.resize(2 * n, 0);
    for (int i = 0; i < n; i++) {
        pr[i] = i;
    }
    int cnt  = n;
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        if (s == 1) {
            int x;
            cin >> x;
            x = (x + (int)z) % n;
            z = (30 * z + 239) % p;
            r[find_set(x).ff]++;
        } else if (s == 2) {
            int x, y;
            cin >> x >> y;
            x = (x + (int)z) % n;
            y = (y + (int)z) % n;
            pair < int, int > xx = find_set(x);
            pair < int, int > yy = find_set(y);
            if (xx.ff == yy.ff) {
                continue;
            }
            int a = xx.ff;
            int b = yy.ff;
            if (rn[a] < rn[b]) {
                swap(a, b);
            }
            pr[b] = a;
            if (rn[a] == rn[b]) {
                ++rn[a];
            }
            pr[cnt] = a;
            r[cnt] = -r[a];
            pr[b] = cnt;
            cnt++;
            z = (13 * z + 11) % p;
        } else {
            int x;
            cin >> x;
            x = (x + (int)z) % n;
            pair < int, int > xx = find_set(x);
            int q = xx.ss - w[x];
            z = (z * 100500 + q) % p;
            cout << q << "\n";
            w[x] = xx.ss;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
vector < int > pr, rn, mn, mx, sz;
int find_set(int v) {
    if (v == pr[v]) {
        return v;
    }
    return pr[v] = find_set(pr[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rn[a] < rn[b]) {
            swap(a, b);
        }
        pr[b] = a;
        sz[a] += sz[b];
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
        if (rn[a] == rn[b]) {
            ++rn[a];
        }
    }
}
int main() {
    int n;
    cin >> n;
    pr.resize(n, 0);
    rn.resize(n, 0);
    mn.resize(n, 0);
    mx.resize(n, 0);
    sz.resize(n, 0);
    for (int i = 0; i < n; i++) {
        pr[i] = i;
        mn[i] = i;
        mx[i] = i;
        sz[i] = 1;
    }
    string s;
    while (cin >> s) {
        if (s == "get") {
            int x;
            cin >> x;
            x--;
            cout << mn[find_set(x)] + 1 << " ";
            cout << mx[find_set(x)] + 1 << " " << sz[find_set(x)]<< "\n";
        } else {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            union_sets(x, y);
        }
    }
}
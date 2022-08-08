#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second;
int pr[200005];
int rn[200005] = {0};
int nt[200005] = {-1};
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
        pr[a] = b;
        if (rn[a] == rn[b]) {
            ++rn[a];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pr[i] = i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t == 1) {
            union_sets(x, y);
        } else if (t == 2) {
            for (int i = x + 1; i <= y; i++) {
                union_sets(x, i);
                if (nt[i] > i) {
                    int o = i;
                    i = nt[i];
                    nt[o] = y;
                } else {
                    nt[i] = y;
                }
            }
        } else {
            if (find_set(x) == find_set(y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
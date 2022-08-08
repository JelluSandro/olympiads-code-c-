#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int pr[50005];
int rn[50005] = {0};
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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        pr[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
    }
    vector < pair < int, pair < int, int > > > o;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (s == "ask") {
            o.push_back({1, {x, y}});
        } else {
            o.push_back({2, {x, y}});
        }
    }
    vector < string > ans;
    for (int i = o.size() - 1; i >= 0; i--) {
        if (o[i].ff == 1) {
            if (find_set(o[i].ss.ff) == find_set(o[i].ss.ss)) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        } else {
            union_sets(o[i].ss.ff, o[i].ss.ss);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << "\n";
    }
}
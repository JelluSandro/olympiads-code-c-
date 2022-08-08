#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
#define int long long
#define mp make_pair
int n, m;
int const INF = 1e18;
int const md = 807;
int pr1[md];
int pr2[md];

void fpr() {
    for (int i = 0; i < md; i++) {
        pr1[i] = i;
        pr2[i] = i;
    }
}

int find_set1(int v) {
    if (v == pr1[v])
        return v;
    return find_set1(pr1[v]);
}

int find_set2(int v) {
    if (v == pr2[v])
        return v;
    return find_set2(pr2[v]);
}

void union_sets1(int a, int b) {
    a = find_set1(a);
    b = find_set1(b);
    if (a != b)
        pr1[b] = a;
}

void union_sets2(int a, int b) {
    a = find_set2(a);
    b = find_set2(b);
    if (a != b)
        pr2[b] = a;
}

void f1() {
    vector < pair < int, pair < pair < int, int >, pair < int, int > > > > g(m);
    for (int i = 0; i < m; i++) {
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        a1--;
        a2--;
        a3--;
        a4--;
        g[i] = mp(a5, mp(mp(a1, a2), mp(a3, a4)));
    }
    vector<int> ans(m + 1, -INF);
    for (int mask = 1; mask < (1 << m); ++mask) {
        fpr();
        int cnt = 0;
        int cur = 0;
        bool flag = 0;
        for (int i = 0; i < m; ++i) {
            if ((mask & (1 << i)) == (1 << i)) {
                int a5 = g[i].ff, a1 = g[i].ss.ff.ff, a2 = g[i].ss.ff.ss, a3 = g[i].ss.ss.ff,
                        a4 = g[i].ss.ss.ss;
                if (find_set1(a1) != find_set1(a2) && find_set2(a3) != find_set2(a4)) {
                    union_sets1(a1, a2);
                    union_sets2(a3, a4);
                    cnt += a5;
                    cur++;
                } else {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) {
            continue;
        }
        ans[cur] = max(ans[cur], cnt);
    }
    for (int i = 1; i <= m; ++i) {
        if (ans[i] == -INF) {
            cout << "Impossible\n";
        } else {
            cout << ans[i] << "\n";
        }
    }
}

void f2() {
    fpr();
    vector < pair < int, pair < int, int > > > g(m);
    for (int i = 0; i < m; i++) {
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        a3--;
        a4--;
        g[i] = mp(a5, mp(a3, a4));
    }
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    vector<int> ans(m, INF);
    int y = 0;
    for (int i = 0; i < m; ++i) {
        if (find_set1(g[i].ss.ff) != find_set1(g[i].ss.ss)) {
            union_sets1(g[i].ss.ff, g[i].ss.ss);
            ans[y] = g[i].ff;
            if (y != 0) {
                ans[y] += ans[y - 1];
            }
            y++;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ans[i] == INF) {
            cout << "Impossible\n";
        } else {
            cout << ans[i] << "\n";
        }
    }
}

void solve() {
    cin >> n >> m;
    if (m <= 20) {
        f1();
    } else {
        if (m == n - 1) {
            f2();
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

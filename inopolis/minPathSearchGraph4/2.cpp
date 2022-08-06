#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    int INF = 1e18;
    int n;
    int s = 1, f = n;
    cin >> n;
    vector <vector<int>> a(n);
    vector <vector<int>> b(n);
    vector<int> r(n, INF);
    vector<int> c(n, 0);
    int m;
    cin >> m >> s >> f;
    for (int i = 0; i < m; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a1--;
        a2--;
        a[a1].push_back(a2);
        a[a2].push_back(a1);
        b[a1].push_back(a3);
        b[a2].push_back(a3);
    }
    set <pair<int, int>> st;
    s--;
    f--;
    st.insert(make_pair(0, s));
    r[s] = 0;
    while (st.size() > 0) {
        pair<int, int> nach = *st.begin();
        st.erase(st.begin());
        int mn = nach.first, my = nach.second;
        if (my == -1) {
            break;
        }
        c[my] = 1;
        for (int i = 0; i < a[my].size(); i++) {
            if (c[a[my][i]] == 0) {
                st.erase(make_pair(r[a[my][i]], a[my][i]));
                r[a[my][i]] = min(r[a[my][i]], r[my] + b[my][i]);
                st.insert(make_pair(r[a[my][i]], a[my][i]));
            }
        }
    }
    cout << r[f];
}

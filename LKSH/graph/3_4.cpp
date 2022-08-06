#include <bits/stdc++.h>

using namespace std;

main() {
    long long INF = 1e18;
    long long n;
    long long s;
    cin >> n;
    vector <vector<long long>> graph(n);
    vector <vector<long long>> ves(n);
    vector<long long> dist(n, INF);
    vector<long long> used(n, 0);
    long long m;
    cin >> m;
    s = 1;
    for (int i = 0; i < m; i++) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        ves[v1].push_back(cost);
        ves[v2].push_back(cost);
    }
    set <pair<long long, long long>> st;
    s--;
    st.insert(make_pair(0, s));
    dist[s] = 0;
    while (st.size() > 0) {
        pair<int, int> mn_ves = *st.begin();
        st.erase(st.begin());
        int ver_min_ves = mn_ves.second;
        if (ver_min_ves == -1) {
            break;
        }
        used[ver_min_ves] = 1;
        for (int i = 0; i < (int) graph[ver_min_ves].size(); i++) {
            if (used[graph[ver_min_ves][i]] == 0) {
                st.erase({dist[graph[ver_min_ves][i]], graph[ver_min_ves][i]});
                dist[graph[ver_min_ves][i]] = min(dist[graph[ver_min_ves][i]], ves[ver_min_ves][i]);
                st.insert({dist[graph[ver_min_ves][i]], graph[ver_min_ves][i]});
            }
        }
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(dist[i], answer);
    }
    cout << answer;
}

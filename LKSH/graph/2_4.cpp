#include <bits/stdc++.h>

using namespace std;

main() {
    long long INF = 1e18;
    long long n;
    long long s, f;
    cin >> n;
    s = 1, f = n;
    vector <vector<long long>> graph(n);
    vector <vector<long long>> ves(n);
    vector<long long> rast(n, INF);
    vector<long long> used(n, 0);
    vector<long long> road(n, 0);
    long long m;
    cin >> m;
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
    f--;
    st.insert(make_pair(0, s));
    rast[s] = 0;
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
                st.erase(make_pair(rast[graph[ver_min_ves][i]], graph[ver_min_ves][i]));
                if (rast[graph[ver_min_ves][i]] > rast[ver_min_ves] + ves[ver_min_ves][i]) {
                    rast[graph[ver_min_ves][i]] = rast[ver_min_ves] + ves[ver_min_ves][i];
                    road[graph[ver_min_ves][i]] = road[ver_min_ves] + 1;
                }
                if (rast[graph[ver_min_ves][i]] == rast[ver_min_ves] + ves[ver_min_ves][i]) {
                    road[graph[ver_min_ves][i]] = max(road[ver_min_ves] + 1, road[graph[ver_min_ves][i]]);
                }
                st.insert(make_pair(rast[graph[ver_min_ves][i]], graph[ver_min_ves][i]));
            }
        }
    }
    if (rast[f] != INF) {
        cout << rast[f] << " " << road[f];
    } else {
        cout << -1;
    }
}

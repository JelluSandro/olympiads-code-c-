#include <bits/stdc++.h>

using namespace std;

main() {
    long long INF = 1e18;
    long long n;
    long long s;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<long long> dist(n, INF);
    vector<long long> used(n, 0);
    s = 1;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    s--;
    dist[s] = 0;
    for (int ii = 0; ii < n; ii++) {
        pair<long long, int> mn_cost;
        mn_cost.first = INF;
        mn_cost.second = -1;
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                if (mn_cost.first > dist[i]) {
                    mn_cost.first = dist[i];
                    mn_cost.second = i;
                }
            }
        }
        int ver_min_cost = mn_cost.second;
        if (ver_min_cost == -1) {
            break;
        }
        used[ver_min_cost] = 1;
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                long long distv = (x[ver_min_cost] - x[i]) * (x[ver_min_cost] - x[i]) +
                                  (y[ver_min_cost] - y[i]) * (y[ver_min_cost] - y[i]);
                dist[i] = min(dist[i], distv);
            }
        }
    }
    long double answer = 0;
    for (int i = 0; i < n; i++) {
        answer += sqrt(dist[i]);
    }
    cout << fixed << setprecision(10) << answer;
}

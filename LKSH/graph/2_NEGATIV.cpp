#include <bits/stdc++.h>

using namespace std;
struct edge {
    int v1, v2, cost;
};

int n, m = 0;
vector <edge> edge_list;
long long INF = 1e18;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost_one;
            cin >> cost_one;
            if (cost_one != 1e5) {
                m++;
                edge edge_one;
                edge_one.v1 = i;
                edge_one.v2 = j;
                edge_one.cost = cost_one;
                edge_list.push_back(edge_one);
            }
        }
    }
    vector<long long> d(n, 0);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < m; ++j)
            if (d[edge_list[j].v2] > d[edge_list[j].v1] + edge_list[j].cost) {
                d[edge_list[j].v2] = max(-INF, d[edge_list[j].v1] + edge_list[j].cost);
                p[edge_list[j].v2] = edge_list[j].v1;
                x = edge_list[j].v2;
            }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];
        vector<int> path;
        for (int cur = y;; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1) {
                break;
            }
        }
        reverse(path.begin(), path.end());

        cout << "YES\n" << (int) path.size() - 1 << endl;
        for (size_t i = 0; i < (int) path.size() - 1; ++i)
            cout << path[i] + 1 << ' ';
    }
}

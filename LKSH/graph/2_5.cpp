#include <bits/stdc++.h>

using namespace std;
struct edge {
    long long vfirst, vsecond, vcost;
};
long long INF = 4e18;
long long n, m, s;
vector<long long> used;
vector <vector<long long>> graph;
vector<long long> answer;

void dfs(long long ver) {
    used[ver] = 1;
    answer[ver] = -1;
    for (int i = 0; i < (int) graph[ver].size(); i++) {
        if (used[graph[ver][i]] == 0) {
            dfs(graph[ver][i]);
        }
    }
}

main() {
    cin >> n >> m >> s;
    used.resize(n, 0);
    graph.resize(n);
    answer.resize(n, 0);
    vector <edge> edge_list;
    vector<long long> r(n, INF);
    for (int i = 0; i < m; i++) {
        long long v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        edge edge_one;
        edge_one.vfirst = v1;
        edge_one.vsecond = v2;
        edge_one.vcost = cost;
        edge_list.push_back(edge_one);
    }
    s--;
    r[s] = 0;
    for (int ii = 0; ii < n - 1; ii++) {
        for (int i = 0; i < m; i++) {
            if (r[edge_list[i].vfirst] < INF) {
                if (r[edge_list[i].vsecond] > r[edge_list[i].vfirst] + edge_list[i].vcost) {
                    r[edge_list[i].vsecond] = max(r[edge_list[i].vfirst] + edge_list[i].vcost, -INF - 1);
                }
            }
        }
    }
    vector<long long> r1(n, INF);
    for (int i = 0; i < n; i++) {
        r1[i] = r[i];
    }
    for (int i = 0; i < m; i++) {
        if (r1[edge_list[i].vfirst] < INF) {
            if (r1[edge_list[i].vsecond] > r1[edge_list[i].vfirst] + edge_list[i].vcost) {
                r1[edge_list[i].vsecond] = max(r1[edge_list[i].vfirst] + edge_list[i].vcost, -INF - 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (r1[i] != r[i]) {
            r[i] = -INF;
            if (used[i] == 0) {
                dfs(i);
            }
        }
        if (r[i] <= -INF) {
            r[i] = -INF;
            if (used[i] == 0) {
                dfs(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (r[i] == INF) {
            cout << "*\n";
        } else {
            if (r[i] <= -INF) {
                cout << "-\n";
            } else {
                if (answer[i] == -1) {
                    cout << "-\n";
                } else
                    cout << r[i] << endl;
            }
        }
    }
}

#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <vector<int>> graph;
vector<int> used;
vector<int> p;
int cycle_st, cycle_end;

bool dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < (int) graph[v].size(); ++i) {
        int to = graph[v][i];
        if (used[to] == 0) {
            p[to] = v;
            if (dfs(to)) return 1;
        } else if (used[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return 1;
        }
    }
    used[v] = 2;
    return 0;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    used.resize(n, 0);
    p.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
    }
    cycle_st = -1;
    for (int i = 0; i < n; ++i) {
        if (dfs(i)) {
            break;
        }
    }
    if (cycle_st == -1) {
        cout << "NO";
    } else {
        cout << "YES\n";
        vector<int> cycle;
        cycle.push_back(cycle_st);
        for (int v = cycle_end; v != cycle_st; v = p[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_st);
        reverse(cycle.begin(), cycle.end());
        for (int i = 0; i < (int) cycle.size() - 1; ++i) {
            cout << cycle[i] + 1 << " ";
        }
    }
}

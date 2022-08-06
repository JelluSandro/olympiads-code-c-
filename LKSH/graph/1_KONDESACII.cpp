#include <bits/stdc++.h>

struct edge {
    int x, y;
};
using namespace std;
int n;
vector <vector<int>> graph;
vector <vector<int>> graph_inverted;
vector<int> topsort;
vector<int> used;
int color = 1;

void top_sort(int v) {
    used[v] = 1;
    for (int i = 0; i < (int) graph[v].size(); i++) {
        int to = graph[v][i];
        if (used[to] == 0) {
            top_sort(to);
        }
    }
    topsort.push_back(v);
}

void dfs(int v) {
    used[v] = color;
    for (int i = 0; i < (int) graph_inverted[v].size(); i++) {
        int to = graph_inverted[v][i];
        if (used[to] == 0) {
            dfs(to);
        }
    }
}

main() {
    cin >> n;
    graph.resize(n);
    graph_inverted.resize(n);
    used.resize(n, 0);
    int m;
    cin >> m;
    vector <edge> reb(m);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph_inverted[v2].push_back(v1);
        reb[i].x = v1;
        reb[i].y = v2;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            top_sort(i);
        }
    }
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    reverse(topsort.begin(), topsort.end());
    for (int i = 0; i < n; i++) {
        if (used[topsort[i]] == 0) {
            dfs(topsort[i]);
            color++;
        }
    }
    set <pair<int, int>> st;
    for (int i = 0; i < m; i++) {
        if (used[reb[i].x] != used[reb[i].y]) {
            st.insert({used[reb[i].x], used[reb[i].y]});
        }
    }
    cout << st.size();
}

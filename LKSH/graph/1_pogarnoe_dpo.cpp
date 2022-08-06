#include <bits/stdc++.h>

using namespace std;
int n;
struct edge {
    int x, y;
};
vector <vector<int>> graph;
vector <vector<int>> graph_inverted;
vector <vector<int>> graph_scc1;
vector <vector<int>> graph_scc2;
vector<int> topsort;
vector<int> used;
int color = 1;

void top_sort(int v) {
    used[v] = 1;
    for (int i = 0; i < (int) graph_inverted[v].size(); i++) {
        int to = graph_inverted[v][i];
        if (used[to] == 0) {
            top_sort(to);
        }
    }
    topsort.push_back(v);
}

void dfs(int v) {
    used[v] = color;
    for (int i = 0; i < (int) graph[v].size(); i++) {
        int to = graph[v][i];
        if (used[to] == 0) {
            dfs(to);
        }
    }
}

int main() {
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
    vector <pair<int, int>> edge;
    vector <pair<int, int>> vx(color, {0, 0});
    for (int i = 1; i < color; i++) {
        vx[i].second = i;
    }
    int cur = 0;
    while ((int) st.size() > 0) {
        edge.push_back(*st.begin());
        st.erase(st.begin());
    }
    graph_scc1.resize(color);
    graph_scc2.resize(color);
    for (int i = 0; i < (int) edge.size(); i++) {
        graph_scc1[edge[i].first].push_back(edge[i].second);
        graph_scc2[edge[i].second].push_back(edge[i].first);
        vx[edge[i].second].first++;
    }
    int cnt = color;
    sort(vx.begin() + 1, vx.end());
    reverse(vx.begin() + 1, vx.end());
    vector<int> it(vx.size());
    vector<int> used_new(color, 0);
    for (int i = 0; i < color; i++) {
        it[vx[i].second] = i;
    }
    for (int i = 1; i < color; i++) {
        if (vx[i].first > 0) {
            cnt -= vx[i].first;
            vx[i].first = 0;
            queue<int> q;
            q.push(vx[i].second);
            for (int j = 0; j < (int) graph_scc2[vx[i].second].size(); j++) {
                if (used_new[graph_scc2[vx[i].second][j]] == 0) {
                    used_new[graph_scc2[vx[i].second][j]] == 1;
                    vx[it[graph_scc2[vx[i].second][j]]].first = 0;
                    q.push(graph_scc2[vx[i].second][j]);
                }
            }
            while (q.size() > 0) {
                for (int j = 0; j < (int) graph_scc1[q.front()].size(); j++) {
                    vx[it[graph_scc1[q.front()][j]]].first--;
                }
                q.pop();
            }
        }
    }
    cout << max(cnt - 1, 1);
}

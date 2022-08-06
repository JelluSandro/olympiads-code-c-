#include <bits/stdc++.h>

using namespace std;
int n;
vector <vector<int>> graph;
vector<int> used;
vector<int> tin;
vector<int> tout;
vector<int> roots;
int tim = 0;

void dfs(int v) {
    used[v] = 1;
    tin[v] = tim;
    tim++;
    for (int i = 0; i < (int) graph[v].size(); i++) {
        if (used[graph[v][i]] == 0) {
            dfs(graph[v][i]);
        }
    }
    tim++;
    tout[v] = tim;
}

int main() {
    freopen("ancestor.in", "r", stdin);
    freopen("ancestor.out", "w", stdout);
    cin >> n;
    graph.resize(n);
    used.resize(n, 0);
    tin.resize(n);
    tout.resize(n);
    for (int i = 0; i < n; i++) {
        int a1;
        cin >> a1;
        if (a1 - 1 >= 0) {
            graph[i].push_back(a1 - 1);
            graph[a1 - 1].push_back(i);
        } else {
            roots.push_back(i);
        }
    }
    for (int i = 0; i < (int) roots.size(); i++) {
        dfs(roots[i]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        if ((tout[a1] > tout[a2]) && (tin[a1] < tin[a2])) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

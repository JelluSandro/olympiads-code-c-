#include <bits/stdc++.h>

using namespace std;
int n, k;
int govno = 1;
bool flag = false;
int cur = 0;
vector <vector<int>> a;
vector<bool> b;
vector<int> c;

void dfs(int v) {
    c[v] = govno;

    b[v] = true;
    for (int i = 0; i < a[v].size(); i++) {
        if (b[a[v][i]] == false) {
            dfs(a[v][i]);
        }

    }
}

int main() {
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    c.resize(n);
    b.resize(n, false);
    for (int i = 0; i < n; i++)
        b[i] = false;
    for (int i = 0; i < k; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a[a1 - 1].push_back(a2 - 1);
        a[a2 - 1].push_back(a1 - 1);
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == false) {
            dfs(i);
            govno++;
        }

    }
    cout << govno - 1 << "\n";
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }

}

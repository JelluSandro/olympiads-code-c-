#include <bits/stdc++.h>

using namespace std;
int n, k;
bool flag = false;
bool gg = false;
int cur = 0;
vector <vector<int>> a;
vector<int> b;
vector<int> c;

void dfs(int v) {
    if (gg == false) {
        //c.push_back(v);
        if (b[v] == 1) {
            cout << "-1";
            flag = true;
            gg = true;
            return;
        } else {
            c.push_back(v);
            b[v] = 1;
            for (int i = 0; i < a[v].size(); i++) {
                if (gg == false)
                    if (b[a[v][i]] != 2) {
                        if (gg == false)
                            dfs(a[v][i]);
                    }
            }
            b[v] = 2;
            c[cur] = v + 1;
            cur++;
        }
    }
}

int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    b.resize(n, 0);
    c.resize(n);
    for (int i = 0; i < n; i++)
        b[i] = false;
    for (int i = 0; i < k; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a[a1 - 1].push_back(a2 - 1);
    }
    for (int i = 0; i < n; i++) {
        if (flag == false)
            if (b[i] == 0) {
                dfs(i);
            }
    }
    if (flag == false)
        for (int i = n - 1; i >= 0; i--)
            cout << c[i] << " ";
}

#include <bits/stdc++.h>

#define int long long
using namespace std;
vector<int> parent;
vector<int> rnk;
vector<int> ves;
vector<int> ot;
int n, m;
int cur = 0;
int cnt = 0;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

int find_sum(int v) {
    // cout<<v;
    cur += ves[v];
    if (v == parent[v]) {
        return v;
    }
    return find_sum(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    // cout<<a<<" "<<b<<endl;
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        //   cout<<b<<" "<<a<<endl;
        ves[b] -= ves[a];
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}

main() {
    cin >> n >> m;
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    rnk.resize(n, 0);
    ves.resize(n, 0);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s == "join") {
            int a1, a2;
            cin >> a1 >> a2;
            union_sets(a1 - 1, a2 - 1);
        }
        if (s == "add") {
            int a1, a2;
            cin >> a1 >> a2;
            a1--;
            int a3 = find_set(a1);
            ves[a3] += a2;
        }
        if (s == "get") {
            int a1;
            cin >> a1;
            a1--;
            cur = 0;
            int a2 = find_sum(a1);
            cout << cur << endl;
        }
    }
}

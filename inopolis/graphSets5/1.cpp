#include <bits/stdc++.h>

#define int long long
using namespace std;
vector<int> parent;
vector<int> rnk;
vector<int> ot;
int n;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void proc(int l) {
    int v = find_set(l);
    ot.push_back(v);
    parent[v] = (v + 1) % n;
}

main() {
    cin >> n;
    parent.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int a1;
        cin >> a1;
        a1--;
        proc(a1);
    }
    for (int i = 0; i < ot.size(); i++) {
        cout << ot[i] + 1 << " ";
    }
}

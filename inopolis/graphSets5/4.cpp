#include <bits/stdc++.h>

#define int long long
using namespace std;
vector<int> parent;
vector<int> rnk;
vector<int> ot;
int n;
bool f = 0;
struct frimen {
    int x, y, z;
};

bool operator<(frimen aa, frimen ba) {
    return aa.z < ba.z;
}

vector <frimen> gr;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    // cout<<a<<" "<<b<<endl;
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    } else {
        f = 1;
    }
}

main() {
    cin >> n;
    parent.resize(n, 0);
    rnk.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        frimen a1;
        cin >> a1.x >> a1.y >> a1.z;
        a1.y--;
        a1.x--;
        gr.push_back(a1);
    }
    sort(gr.begin(), gr.end());
    int cnt = 0;
    int ot = 0;
    for (int i = 0; i < m; i++) {
        f = 0;
        union_sets(gr[i].x, gr[i].y);
        if (f == 0) {
            cnt++;
            ot += gr[i].z;
            if (cnt == n - 1) {

                break;
            }
        }
    }
    cout << ot;
}

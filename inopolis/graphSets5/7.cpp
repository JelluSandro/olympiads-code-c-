#include <bits/stdc++.h>

#define int long long
using namespace std;
vector<int> parent;
vector<int> rnk;
vector<int> ot;
vector<int> used;
int n;
bool f = 0;
int ss;
struct frimen {
    int x, y, z, w;
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

void union_sets(int a, int b, int w) {
    // cout<<a<<" "<<b<<endl;
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        used[w] = 1;
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
    cin >> m >> ss;
    used.resize(m, 0);
    for (int i = 0; i < m; i++) {
        frimen a1;
        cin >> a1.x >> a1.y >> a1.z;
        a1.w = i;
        a1.y--;
        a1.x--;
        gr.push_back(a1);
    }
    sort(gr.begin(), gr.end());
    reverse(gr.begin(), gr.end());
    vector<int> ans;
    int cnt = 0;
    int ot = 0;
    for (int i = 0; i < m; i++) {
        f = 0;
        union_sets(gr[i].x, gr[i].y, gr[i].w);
        if (f == 0) {
            cnt++;
            if (cnt == n - 1) {

                break;
            }
        }
    }
    sort(gr.begin(), gr.end());
    for (int i = 0; i < m; i++) {
        if (used[gr[i].w] == 0) {
            if (ot + gr[i].z <= ss) {
                ot += gr[i].z;
                ans.push_back(gr[i].w + 1);
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

}

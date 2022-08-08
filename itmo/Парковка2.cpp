#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
vector < int > pr, rn;
int find_set(int v) {
    if (v == pr[v]) {
        return v;
    }
    return pr[v] = find_set(pr[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        pr[a] = b;
    }
}
int main() {
    int n;
    cin >> n;
    pr.resize(n, 0);
    rn.resize(n, 0);
    for (int i = 0; i < n; i++) {
        pr[i] = i;
    }
    string s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        int v = find_set(x);
        if (v == x) {
            cout << x + 1 << " ";
            union_sets(x, (x + 1) % n);
        } else {
            cout << v + 1 << " ";
            union_sets(v, (v + 1) % n);
        }
    }
}
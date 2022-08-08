#include <bits/stdc++.h>

using namespace std;

int main() {
    int INF = 1e8;
    int n;
    cin >> n;
    vector<int> a(n);
    vector <pair<int, int>> b(n + 1, {INF, 0});
    vector <pair<int, int>> c(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]].first = min(b[a[i]].first, i);
        b[a[i]].second = max(b[a[i]].first, i);
    }
    for (int i = 0; i <= n; i++) {
        if (b[i].first != INF) {
            c[b[i].first].first = 1;
            c[b[i].first].second = b[i].second;
            c[b[i].second].first = 2;
            c[b[i].second].second = b[i].first;
        }
    }
    int cnt = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (c[i].first == 1) {
            r = max(r, c[i].second);
        }
        if (i >= r) {
            cnt++;
        }
    }
    cout << cnt;
}

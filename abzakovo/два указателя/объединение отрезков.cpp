#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    int const mix = 199999;
    int const kek = 50000;
    ios_base::sync_with_stdio(false);
    ifstream cin("merge.in");
    ofstream cout("merge.out");
    int n;
    cin >> n;
    vector <pair<int, int>> a(n);
    vector<int> b(n * 5);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    int l = a[0].first;
    int r = a[0].second;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first >= l) {
            if (a[i].first <= r) {
                r = max(r, a[i].second);
            } else {
                b[cnt] = l;
                cnt++;
                b[cnt] = r;
                cnt++;
                l = a[i].first;
                r = a[i].second;
            }
        }
    }
    b[cnt] = l;
    cnt++;
    b[cnt] = r;
    cnt++;
    cout << cnt / 2 << "\n";
    for (int i = 0; i < cnt; i = i + 2) {
        cout << b[i] << " " << b[i + 1] << "\n";
    }
}

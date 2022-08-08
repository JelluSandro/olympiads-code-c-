#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector < vector < pair < int, int > > > a(k);
    for (int i = 0; i < k; ++i) {
        int r;
        cin >> r;
        for (int j = 0; j < r; j++) {
            int a1, a2;
            cin >> a1 >> a2;
            a1--;
            a2--;
            if (a2 < a1) {
                swap(a1, a2);
            }
            a[i].push_back({a1, a2});
        }
    }
    vector < int > b(n);
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            b[i] = (mask & (1 << i)) / (1 << i);
            cnt += b[i];
        }
        vector < int > c(n, 0);
        for (int i = 0; i < cnt; i++) {
            c[n - i - 1] = 1;
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < (int)a[i].size(); j++) {
                if (b[a[i][j].ff] > b[a[i][j].ss]) {
                    swap(b[a[i][j].ff], b[a[i][j].ss]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] != c[i]) {
                cout <<"No";
                return 0;
            }
        }
    }
    cout << "Yes";
}
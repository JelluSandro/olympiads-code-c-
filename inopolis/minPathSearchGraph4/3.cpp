#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int d[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

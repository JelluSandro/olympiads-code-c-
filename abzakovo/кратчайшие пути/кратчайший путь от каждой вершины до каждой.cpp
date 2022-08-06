#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n][n];
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            a[i][j] = 9999999;
            if (i == j)
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a[a1 - 1][a2 - 1] = min(a3, a[a1 - 1][a2 - 1]);
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++) {
            if (i != j)
                cout << a[i][j] << " ";
            else
                cout << 0 << " ";
        }
    }
}

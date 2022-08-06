#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n + 2][m + 2];
    for (int i = 0; i < n + 2; i++) {

        for (int j = 0; j < m + 2; j++) {
            a[i][j] = 0;
        }
    }
    a[2][2] = 1;
    for (int i = 2; i < n + 2; i++) {

        for (int j = 2; j < m + 2; j++) {
            a[i][j] = a[i][j] + a[i - 1][j - 2] + a[i - 2][j - 1];
        }
    }

    cout << a[n + 1][m + 1];
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n] = {0};
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {

            if (i - j >= 0) {

                a[i] = a[i] + a[i - j];
            }
        }
    }
    cout << a[n - 1];
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("pathmgep.in","r",stdin);
//freopen ("pathmgep.out","w",stdout);
    ios_base::sync_with_stdio(false);
    long long INF = 1e18;
    int n, m, k;
    bool flag = false;
    long long cnt = 0, cur = 0, mn = 0;
    cin >> n >> m >> k;
    long long a[n][n];
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == j)
                a[i][j] = 0;
        }
    }
    long long b[n];
    for (int i = 0; i < n; i++)
        b[i] = INF;
    b[m - 1] = 0;
    bool used[n];
    for (int i = 0; i < n; i++)
        used[i] = false;
    while (flag == false) {
        cnt = 0;
        mn = INF;
        for (int i = 0; i < n; i++) {

            if (used[i] == false) {
                if (b[i] < mn) {

                    mn = b[i];
                    cnt = i;
                }
            }
        }
        if (mn != INF) {
            for (int i = 0; i < n; i++) {
                if (a[cnt][i] > 0)
                    b[i] = min(b[i], b[cnt] + a[cnt][i]);
            }
            used[cnt] = true;
        } else
            flag = true;
        if (used[k - 1] == true) {

            break;
        }
    }
    if (b[k - 1] != INF)
        cout << b[k - 1];
    else
        cout << -1;
}

#include <bits/stdc++.h>

using namespace std;
int a[309 + 2][309 + 2];
int INF = 1e9 + 3;
int n, m;
int c[309 + 2][309 + 2];
int d[309 + 2][309 + 2];

void chip(int x, int y, int cnt) {

    c[x][y] = cnt;
    if (a[x + 1][y + 1] <= a[x][y + 1]) {
        if (c[x - 1][y] > c[x][y] + 1) {
            chip(x - 1, y, cnt + 1);
        }
    }
    if (a[x + 1][y + 1] <= a[x + 2][y + 1]) {
        if (c[x + 1][y] > c[x][y] + 1) {
            chip(x + 1, y, cnt + 1);
        }
    }
    if (a[x + 1][y + 1] <= a[x + 1][y]) {
        if (c[x][y - 1] > c[x][y] + 1) {
            chip(x, y - 1, cnt + 1);
        }
    }
    if (a[x + 1][y + 1] <= a[x + 1][y + 2]) {
        if (c[x][y + 1] > c[x][y] + 1) {
            chip(x, y + 1, cnt + 1);
        }
    }
}

void dail(int x, int y, int cnt) {

    d[x][y] = cnt;
    if (a[x + 1][y + 1] >= a[x][y + 1]) {
        if (d[x - 1][y] > d[x][y] + 1) {
            dail(x - 1, y, cnt + 1);
        }
    }
    if (a[x + 1][y + 1] >= a[x + 2][y + 1]) {
        if (d[x + 1][y] > d[x][y] + 1) {
            dail(x + 1, y, cnt + 1);
        }
    }
    if (a[x + 1][y + 1] >= a[x + 1][y]) {
        if (d[x][y - 1] > d[x][y] + 1) {
            dail(x, y - 1, cnt + 1);
        }
    }
    if (a[x + 1][y + 1] >= a[x + 1][y + 2]) {
        if (d[x][y + 1] > d[x][y] + 1) {
            dail(x, y + 1, cnt + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = INF;
            d[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    c[x][y] = 0;
    for (int i = 0; i <= n + 1; i++) {
        a[i][0] = -1;
        a[i][m + 1] = -1;
    }
    for (int i = 0; i <= m + 1; i++) {
        a[0][i] = -1;
        a[n + 1][i] = -1;
    }
    chip(x, y, 0);
    int s, f;
    cin >> s >> f;
    s--;
    f--;
    d[s][f] = 0;
    for (int i = 0; i <= n + 1; i++) {
        a[i][0] = INF + 1;
        a[i][m + 1] = INF + 1;
    }
    for (int i = 0; i <= m + 1; i++) {
        a[0][i] = INF + 1;
        a[n + 1][i] = INF + 1;
    }
    dail(s, f, 0);
    int mn = INF;
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] != INF) {
                if (d[i][j] != INF) {
                    if (mn > max(c[i][j], d[i][j])) {
                        mn = max(c[i][j], d[i][j]);
                        a1 = i;
                        a2 = j;
                    }
                }
            }
        }
    }
    if (mn == INF) {
        cout << -1;
        return 0;
    }
    cout << mn << endl << a1 + 1 << " " << a2 + 1;
}

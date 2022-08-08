#include <bits/stdc++.h>

using namespace std;
int k;
int n, m, t;
int xs, ys, xf, yf;
int b[100][100];

void check(vector<int> a, int v) {
    int x = 10 + xs, y = 10 + ys;
    for (int i = 0; i < v; i++) {
        if (a[i] == 1) {
            x++;
        }
        if (a[i] == 2) {
            x--;
        }
        if (a[i] == 3) {
            y++;
        }
        if (a[i] == 4) {
            y--;
        }
        if (b[x][y] == 1) {
            break;
        } else {
            if (i == v - 1) {
                if ((x == 10 + xf) && (y == 10 + yf)) {
                    int cnt = 0;
                    for (int j = 1; j < v; j++) {
                        if (a[j - 1] != a[j]) {
                            cnt++;
                        }
                    }
                    if (cnt <= t) {
                        for (int j = 0; j < v; j++) {
                            if (a[j] == 1) {
                                cout << "D";
                            }
                            if (a[j] == 2) {
                                cout << "U";
                            }
                            if (a[j] == 3) {
                                cout << "R";
                            }
                            if (a[j] == 4) {
                                cout << "L";
                            }
                        }
                        cout << endl;
                        break;
                    }
                }
            }
        }
    }

}

void build(vector<int> a, int v) {
    for (int ii = 1; ii < 5; ii++) {
        a[v] = ii;
        check(a, v + 1);
        if (v + 1 != k) {
            build(a, v + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            b[i][j] = 1;
        }
    }
    cin >> n >> m >> k >> t;
    cin >> xs >> ys >> xf >> yf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i + 10][j + 10] = 0;
        }
    }
    xs--;
    ys--;
    xf--;
    yf--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                b[i + 10][j + 10] = 1;
            }
        }
    }
    vector<int> prob(k, 0);
    build(prob, 0);
}

#include <bits/stdc++.h>

using namespace std;
int t[130][130][130];
int n;

int sum(int x, int y, int z) {
    int result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            for (int ii = z; ii >= 0; ii = (ii & (ii + 1)) - 1) {
                result += t[i][j][ii];
            }
        }
    }
    return result;
}

void inc(int x, int y, int z, int delta) {
    for (int i = x; i < n; i = (i | (i + 1))) {
        for (int j = y; j < n; j = (j | (j + 1))) {
            for (int ii = z; ii < n; ii = (ii | (ii + 1))) {
                t[i][j][ii] += delta;
            }
        }
    }
}

int main() {
    cin >> n;
    n++;
    int ask;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int ii = 0; ii < n; ii++) {
                t[i][j][ii] = 0;
            }
        }
    }
    while (cin >> ask) {
        if (ask == 2) {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << sum(x2 + 1, y2 + 1, z2 + 1) - sum(x2 + 1, y2 + 1, z1) - sum(x1, y2 + 1, z2 + 1) +
                    sum(x1, y2 + 1, z1) - sum(x2 + 1, y1, z2 + 1) + sum(x1, y1, z2 + 1) + sum(x2 + 1, y1, z1) -
                    sum(x1, y1, z1) << endl;
        } else {
            int x, y, z, key;
            cin >> x >> y >> z >> key;
            inc(x + 1, y + 1, z + 1, key);
        }
    }
}

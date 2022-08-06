#include <bits/stdc++.h>

using namespace std;
int n;
long long sum[130][130][130];
long long mass[130][130][130];

void add(long long x, long long y, long long z, long long k) {
    for (; x <= n; x = (x | (x - 1)) + 1) {
        for (; y <= n; y = (y | (y - 1)) + 1) {
            for (; z <= n; z = (z | (z - 1)) + 1) {
                sum[x][y][z] += k;
            }
        }
    }
}

long long answer(long long x, long long y, long long z) {
    long long result = 0;
    for (; x > 0; x = (x & (x - 1))) {
        for (; y > 0; y = (y & (y - 1))) {
            for (; z > 0; z = (z & (z - 1))) {
                result += mass[x][y][z];
            }
        }
    }
    return result;
}

int main() {
    cin >> n;
    for (int ii = 0; ii < 130; ii++) {
        for (int i = 0; i < 130; i++) {
            for (int j = 0; j < 130; j++) {
                sum[ii][i][j] = 0;
                mass[ii][i][j] = 0;
            }
        }
    }
    int c;
    while (cin >> c) {
        if (c == 1) {
            long long x, y, z, k;
            cin >> x >> y >> z >> k;
            add(x + 1, y + 1, z + 1, k);
        }
        if (c == 2) {
            long long x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            long long res = answer(x2 + 1, y2 + 1, z2 + 1) - answer(x2 + 1, y2 + 1, z1) - answer(x1, y2 + 1, z2 + 1) +
                            answer(x1, y2 + 1, z1) - answer(x2 + 1, y1, z2 + 1) - answer(x1, y1, z1) +
                            answer(x2 + 1, y1, z1) + answer(x1, y1, z2 + 1);
            cout << res << " " << answer(x2 + 1, y2 + 1, z2 + 1) << endl;
        }
    }
}

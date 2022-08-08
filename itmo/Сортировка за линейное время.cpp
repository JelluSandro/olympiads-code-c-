#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
vector < unsigned int > g[1025];
int n, t;
int a, b;
unsigned int cur = 0;
unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}
unsigned int nextRand32() {
    unsigned int a = nextRand24(), b = nextRand24();
    return ((a << 8) ^ b);
}
void q(int d, int l, int r) {
    if (l >= r) {
        return;
    }
    unsigned int x = g[d][l + (r - l) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (g[d][i] < x) i++;
        while (g[d][j] > x) j--;
        if (i <= j) {
            swap(g[d][i], g[d][j]);
            i++;
            j--;
        }
    }
    if (i < r) {
        q(d, i, r);
    }
    if (j > l) {
        q(d, l, j);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> a >> b;
        int kk = (1 << 22);
        for (int i = 0; i < n; i++) {
            unsigned int x = nextRand32();
            g[x / kk].push_back(x);
        }
        unsigned long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < 1025; i++) {
            int to = (int)g[i].size();
            if (to == 0) continue;
            if (to != 1) {
                q(i, 0, to - 1);
            }
            for (int j = 0; j < to; j++) {
                sum += (long long)cnt * g[i][j];
                cnt++;
            }
            g[i].clear();
        }
        cout << sum << '\n';
    }
}
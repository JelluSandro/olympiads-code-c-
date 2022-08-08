#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
vector < int > pr, rn, color, r;
pair < int, int > find_set(int v) {
    if (v == pr[v]) {
        return {v, 0};
    }
    pair < int, int > xx = find_set(pr[v]);
    return {xx.first, xx.second + 1};
}
void union_sets(int a, int b) {
    a = find_set(a).first;
    b = find_set(b).first;
    if (a != b) {
        if (rn[a] < rn[b]) {
            swap(a, b);
        }
        pr[b] = a;
        if (rn[a] == rn[b]) {
            ++rn[a];
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    pr.resize(2 * n, 0);
    rn.resize(2 * n, 0);
    color.resize(2 * n, 0);
    for (int i = 0; i < n; i++) {
        pr[i] = i;
    }
    int sh = 0;
    int cnt  = n;
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        int x, y;
        cin >> x >> y;
        x = (x + sh) % n;
        y = (y + sh) % n;
        pair < int, int > xx = find_set(x);
        pair < int, int > yy = find_set(y);
        if (xx.ss % 2 == 0) {
            color[x] = color[xx.first];
        } else {
            color[x] = color[xx.first] ^ 1;
        }
        if (yy.ss % 2 == 0) {
            color[y] = color[yy.first];
        } else {
            color[y] = color[yy.first] ^ 1;
        }
        if (s == 0) {
            if (color[x] == color[y]) {
                if (color[xx.first] != color[yy.first]) {
                    pr[cnt] = xx.ff;
                    pr[yy.ff] = cnt;
                    cnt++;
                } else {
                    pr[yy.ff] = xx.ff;
                }
            } else {
                if (color[xx.first] == color[yy.first]) {
                    pr[cnt] = xx.ff;
                    pr[yy.ff] = cnt;
                    cnt++;
                } else {
                    pr[yy.ff] = xx.ff;
                }
            }
        } else {
            if (color[x] == color[y]) {
                cout << "YES\n";
                sh = (sh + 1) % n;
            } else {
                cout << "NO\n";
            }
        }
    }
}
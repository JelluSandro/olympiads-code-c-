#include <bits/stdc++.h>

#define ld long double
#define int long long
using namespace std;
struct Node {
    int x1, y1, x2, y2;
};

main() {
    int m = 2e9;
    int n;
    cin >> n;
    vector <Node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    int color = 1;
    map<int, int> mp;
    map<int, int> col;
    for (int i = 0; i < n; i++) {
        if (mp[a[i].x1 * m + a[i].y1] != 0) {
            if (mp[a[i].x2 * m + a[i].y2] == 0) {
                mp[a[i].x2 * m + a[i].y2] = col[mp[a[i].x1 * m + a[i].y1]];
            } else {
                if (col[mp[a[i].x2 * m + a[i].y2]] == col[mp[a[i].x1 * m + a[i].y1]]) {
                    cout << i + 1;
                    return 0;
                } else {
                    col[mp[a[i].x2 * m + a[i].y2]] = col[mp[a[i].x1 * m + a[i].y1]];
                }
            }
        } else {
            if (mp[a[i].x2 * m + a[i].y2] != 0) {
                mp[a[i].x1 * m + a[i].y1] = col[mp[a[i].x2 * m + a[i].y2]];
            } else {
                mp[a[i].x1 * m + a[i].y1] = color;
                mp[a[i].x2 * m + a[i].y2] = color;
                col[color] = color;
                color++;
            }
        }
    }
    cout << 0;
}

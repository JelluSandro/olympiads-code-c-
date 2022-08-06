#include <bits/stdc++.h>

using namespace std;
#define int long long

main() {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++) {
        int cnt = 0, cur = 0, ver = 0, gra = 0;
        char x = '!';
        for (int i = 0; i < n; i++) {
            if (cur == 2) {
                if (a[i][j] == x) {
                    gra++;
                } else {
                    if (gra == ver) {
                        for (int i =)
                            cur = 0;
                        gra = 0;
                        cnt = 0;
                        ver = 0;
                    } else {
                        if (gra > ver) {
                            cnt = gra;
                            cur = 1;
                            ver = 1;
                            gra = 0;
                            x = a[i][j];
                        } else {
                            cur = 2;
                            cnt = ver;
                            ver = gra;
                            gra = 1;
                            x = a[i][j];
                        }
                    }
                }
            }
            if (cur == 1) {
                if (a[i][j] == x) {
                    ver++;
                } else {
                    if (cnt < ver) {
                        cur = 1;
                        cnt = ver;
                        ver = 1;
                        x = a[i][j];
                        gra = 0;
                    } else {
                        cnt = ver;
                        gra = 1;
                        cur = 2;
                        x = a[i][j];
                    }
                }
            }
            if (cur == 0) {
                if (a[i][j] == x || x == '!') {
                    x = a[i][j];
                    cnt++;
                } else {
                    cur = 1;
                    ver = 1;
                    x = a[i][j];
                }
            }
        }
    }
}

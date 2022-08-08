#include <iostream>
#include <set>

using namespace std;

int main() {
    int const mix = 1000000;
    int cnt = 0, mn = 0, cur = 0;
    int n, k;
    cin >> n >> k;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    int b[n];
    for (int i = 0; i < n; i++) {
        b[i] = mix;
    }
    bool v[n];
    for (int i = 0; i < n; i++) {
        v[i] = false;
    }
    b[0] = 0;
    for (int i = 0; i < k; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a[a1][a2] = a3;
        a[a2][a1] = a3;
    }
    do {
        cnt = mix;
        mn = mix;
        for (int i = 0; i < n; i++) {
            if (v[i] == false) {
                if (b[i] < mn) {
                    cnt = i;
                    mn = b[i];
                }
            }
        }
        if (cnt != mix) {
            for (int i = 0; i < n; i++) {
                if (a[cnt][i] > 0) {
                    cur = mn + a[cnt][i];
                    if (cur < b[i]) {
                        b[i] = cur;
                    }
                }
            }
            v[cnt] = true;
        }

    } while (cnt < mix);
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

}

#include <iostream>

using namespace std;
int const mix = 10000;
int a[mix];
int n;

void f(int l, int r) {
    if (l == r)return;
    if (r - l == 1) {
        if (a[l] > a[r]) {
            swap(a[l], a[r]);
        }
        return;
    }
    int m = (l + r) / 2;
    f(l, m);
    f(m + 1, r);
    int b[mix];
    int xl = l;
    int xm = m + 1;
    int cnt = 0;
    while (r - l + 1 != cnt) {
        if (xl > m) {
            for (int i = xm; i < r + 1; i++) {
                b[cnt] = a[i];
                cnt++;
                xm++;
            }
        } else {
            if (xm > r) {
                for (int i = xl; i < m + 1; i++) {
                    b[cnt] = a[i];
                    cnt++;
                    xl++;
                }
            } else {
                if (a[xl] > a[xm]) {
                    b[cnt] = a[xm];
                    cnt++;
                    xm++;
                } else {
                    b[cnt] = a[xl];
                    cnt++;
                    xl++;
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        a[i + l] = b[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    f(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

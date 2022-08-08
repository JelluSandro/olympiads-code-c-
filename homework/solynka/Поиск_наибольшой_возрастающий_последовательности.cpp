#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int l = 0, r = 0;
    int xl = 0, xr = 0;
    int cnt = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            if (mx < cnt) {
                xl = l;
                xr = r;
                mx = cnt;
            }
            l = i;
            r = i;
            cnt = 0;
        } else {
            r++;
            cnt++;
        }
    }
    if (mx < cnt) {
        xl = l;
        xr = r;
        mx = cnt;
    }
    cout << mx + 1 << endl;
    for (int i = xl; i < xr + 1; i++) {
        cout << a[i] << " ";
    }
}

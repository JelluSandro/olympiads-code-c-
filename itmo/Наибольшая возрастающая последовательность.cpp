#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int const mix = 1e9;
    cin >> n;
    vector < int > a(n);
    vector < int > c(n);
    vector < int > b(n + 1);
    for (int i = 0; i <= n; i++) {
        b[i] = mix;
    }
    b[0] = -1 * mix;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int l = 0;
        int r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (a[i] > b[m])
                l = m;
            else
                r = m;
        }
        if (b[l + 1] == mix)
            cnt++;
        b[l + 1] = a[i];
        c[i] = b[l];
    }
    vector < int > dd(cnt);
    int cur = 0;
    int df = b[cnt];
    cout << cnt << "\n";
    for (int i = n - 1; i >= 0; i--) {
        if (df == a[i]) {
            dd[cur] = df;
            cur++;
            df = c[i];
        }
    }
    for (int i = cnt - 1; i >= 0; i--) {
        cout << dd[i] << " ";
    }
    return 0;
}
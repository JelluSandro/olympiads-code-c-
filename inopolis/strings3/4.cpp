#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    string s;
    cin >> s;
    int n = s.size();
    int p[n];
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int x = p[i - 1];
        while ((x > 0) && (s[i] != s[x])) {
            x = p[x - 1];
        }
        if (s[x] == s[i]) {
            x++;
        }
        p[i] = x;
    }
    int gg = 0;
    int y = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] - p[i - 1] != 1) {
            gg = 1;
            break;
        }
        if (p[i - 1] == 0) {
            gg = 2;
            break;
        }
        y++;
    }

    if (gg == 2) {
        if (n % (n - y - 1) == 0)
            cout << n - y - 1;
        else
            cout << n;
    } else {
        cout << n;
    }
}

#include <bits/stdc++.h>

#define int long long

using namespace std;

main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            cnt += i + 1;
        }
    }
    cout << cnt;
}

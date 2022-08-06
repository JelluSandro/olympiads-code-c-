#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("ones.in", "r", stdin);
    freopen("ones.out", "w", stdout);
    int n;
    cin >> n;
    long long a[n + 3];
    a[0] = 2;
    a[1] = 4;
    a[2] = 7;
    for (int i = 3; i < n + 1; i++) {

        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    cout << a[n - 1];
}

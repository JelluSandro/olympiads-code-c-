#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int n, k, a1, b, c;
int const mm = 3 * 1e7 + 1;
int arr[mm];
 
void q(int l, int r) {
    if (r - l <= 1) {
        return;
    }
    int x = arr[rand() % (r-l) + l];
    int ii = l;
    int jj = l;
    for (int i = l; i < r; i++) {
        if (arr[i] == x) {
            swap(arr[i], arr[jj++]);
        }
        if (arr[i] < x) {
            swap(arr[i], arr[jj]);
            swap(arr[jj++], arr[ii++]);
        }
    }
    if (k - 1 == x) {
        return;
    }
    if (k - 1 >= l && ii > k - 1) {
        q(l, ii);
    } else {
        q(jj, r);
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> a1 >> b >> c >> arr[0] >> arr[1];
    for (int i = 2; i < n; ++i) {
        arr[i] = a1 * arr[i - 2] + b * arr[i - 1] + c;
    }
    q(0, n);
    cout << arr[k - 1];
}
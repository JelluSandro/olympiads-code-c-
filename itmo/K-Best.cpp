#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ld long double
int n, k;
ld u[(int)1e5 + 7];
ld w[(int)1e5 + 7];
vector < ld > b;
void q(vector < ld >& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    ld x = arr[l + (r - l) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (i < r) {
        q(arr, i, r);
    }
    if (j > l) {
        q(arr, l, j);
    }
}
void qq(vector < pair <ld, int> >& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    ld x = arr[l + (r - l) / 2].ff;
    int i = l;
    int j = r;
    while (i <= j) {
        while (arr[i].ff < x) i++;
        while (arr[j].ff > x) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (i < r) {
        qq(arr, i, r);
    }
    if (j > l) {
        qq(arr, l, j);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> w[i];
    }
    ld l = 0, r = 1e9;
    for (int ii = 0; ii < 50; ii++) {
        ld m = l + (r - l) / 2;
        ld sum = 0;
        for (int i = 0; i < n; i++) {
            b[i] = u[i] - m * w[i];
        }
        q(b, 0, n - 1);
        for (int i = n - 1; i > n - 1 - k; i--) {
            sum += b[i];
        }
        if (sum >= 0) {
            l = m;
        } else {
            r = m;
        }
    }
    vector<pair<long double, int> > ans(n);
    for (int i = 0; i < n; i++) {
        ans[i].first = u[i] - w[i] * l;
        ans[i].second = i + 1;
    }
    qq(ans, 0, n - 1);
    for (int i = n - 1; i > n - 1 - k; i--) {
        cout << ans[i].second << " ";
    }
}
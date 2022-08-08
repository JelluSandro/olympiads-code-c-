#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int n, m, k;
vector < pair < string, string > > a(1001);
void merge(vector < pair < string, string > >& arr, int l, int r) {
    if (l != r) {
        int m = (l + r) / 2;
        merge(arr, l, m);
        merge(arr, m + 1, r);
        int jj = m + 1;
        vector < pair < string, string > > b(r - l + 1);
        int cnt = 0;
        for (int i = l; i < m + 1; i++) {
            while (arr[i].ff > arr[jj].ff && jj < r + 1) {
                b[cnt++] = arr[jj++];
            }
            b[cnt++] = arr[i];
        }
        for (; jj < r + 1; jj++) {
            b[cnt++] = arr[jj];
        }
        for (int i = 0; i < r - l + 1; i++) {
            arr[i + l] = b[i];
        }
    }
}
 
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].ss;
    }
    for (int i = 0; i < n; i++) {
        a[i].ff = a[i].ss.substr(m - k, k);
    }
    merge(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i].ss << "\n";
    }
}
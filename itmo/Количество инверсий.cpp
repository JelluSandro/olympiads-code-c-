#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int n, mm, k;
vector < int > arr;
long long ans = 0;
unsigned int cur = 0;
int aa, bb;
unsigned int nextRand24() {
    cur = cur * aa + bb;
    return cur >> 8;
}
void merge(int l, int r) {
    if (l != r) {
        int m = (l + r) / 2;
        merge(l, m);
        merge(m + 1, r);
        int jj = m + 1;
        vector < int > b(r - l + 1);
        int cnt = 0;
        for (int i = l; i < m + 1; i++) {
            while (arr[i] > arr[jj] && jj < r + 1) {
                b[cnt] = arr[jj];
                ans += (long long)m - i + 1;
                cnt++;
                jj++;
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
    cin >> n >> mm;
    arr.resize(n);
    cin >> aa >> bb;
    for (int i = 0; i < n; i++) {
        arr[i] = nextRand24() % mm;
    }
    merge(0, n - 1);
    cout << ans;
    return 0;
}
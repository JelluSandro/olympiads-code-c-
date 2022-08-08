#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int n;
vector < int > a;
int cnt;
void f(int l, int r) {
    if (l > r) return;
    if (l == r) {
        a[l] = cnt;
        cnt--;
        return;
    }
    int m = (r + l) / 2;
    a[m] = cnt;
    cnt--;
    f(l, m - 1);
    f(m + 1, r);
}
 
int main() {
    cin >> n;
    cnt = n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        swap(a[i], a[i / 2]);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
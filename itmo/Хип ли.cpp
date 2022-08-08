#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 
int main() {
    int n;
    cin >> n;
    vector < int > a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i * 2 <= n) {
            if (a[i] > a[i * 2]) {
                cout << "NO";
                return 0;
            }
        }
        if (i * 2 + 1 <= n) {
            if (a[i] > a[i * 2  + 1]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
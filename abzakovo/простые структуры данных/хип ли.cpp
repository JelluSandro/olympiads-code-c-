#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("isheap.in");
    ofstream cout("isheap.out");
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {

        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i * 2 + 1 < n) {

            if (a[i] > a[i * 2 + 1]) {

                cout << "NO";
                return 0;
            }
            if (i * 2 + 2 > n) {
                if (a[i] > a[i * 2 + 2]) {

                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
}

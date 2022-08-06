#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("binsearch.in");
    ofstream cout("binsearch.out");
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {

        cin >> a[i];
    }
    int m1;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        int h;
        cin >> h;
        int r = n - 1, l = 0;
        while (r - l > 1) {
            int g = (l + r) / 2;
            if (a[g] > h) {

                r = g;
            } else {
                if (a[g] < h) {

                    l = g;
                } else {
                    r = g;
                }
            }

        }
        if (a[l] == h) {

            cout << l + 1 << " ";
        } else {

            if (a[r] == h) {

                cout << r + 1 << " ";
            } else {

                cout << -1 << " ";
            }
        }
        r = n - 1, l = 0;
        while (r - l > 1) {
            int g = (l + r) / 2;
            if (a[g] > h) {

                r = g;
            } else {
                if (a[g] < h) {

                    l = g;
                } else {
                    l = g;
                }
            }

        }
        if (a[r] == h) {

            cout << r + 1 << "\n";
        } else {

            if (a[l] == h) {

                cout << l + 1 << "\n";
            } else {

                cout << -1 << "\n";
            }
        }

    }
}

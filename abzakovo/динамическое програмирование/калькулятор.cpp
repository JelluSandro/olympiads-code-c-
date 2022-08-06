#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("calcul.in", "r", stdin);
    freopen("calcul.out", "w", stdout);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << "\n";
        cout << 1;
        return 0;
    }
    int a[n + 1];
    string b[n + 1];
    a[1] = 0;
    a[2] = 1;
    a[3] = 1;
    b[2] = '2';
    b[3] = '3';
    for (int i = 4; i < n + 1; i++) {
        if (i % 2 == 0) {
            if (i % 3 == 0) {
                if (a[i / 2] < a[i / 3]) {
                    if (a[i / 2] > a[i - 1]) {
                        b[i] = b[i - 1] + '1';
                    } else {

                        b[i] = b[i / 2] + '2';
                    }
                } else {

                    if (a[i / 3] > a[i - 1]) {
                        b[i] = b[i - 1] + '1';
                    } else {
                        b[i] = b[i / 3] + '3';
                    }
                }
                a[i] = min(min(a[i / 2], a[i / 3]), a[i - 1]) + 1;
            } else {

                if (a[i / 2] > a[i - 1]) {
                    b[i] = b[i - 1] + '1';
                } else {
                    b[i] = b[i / 2] + '2';
                }
                a[i] = min(a[i / 2], a[i - 1]) + 1;
            }
        } else {
            if (i % 3 == 0) {
                if (a[i / 3] > a[i - 1]) {
                    b[i] = b[i - 1] + '1';
                } else {
                    b[i] = b[i / 3] + '3';

                }
                a[i] = min(a[i / 3], a[i - 1]) + 1;
            } else {
                b[i] = b[i - 1] + '1';
                a[i] = a[i - 1] + 1;
            }
        }
    }
    cout << b[n].size() << "\n";
    cout << 1 << " ";
    int cur = 1;
    for (int i = 0; i < b[n].size(); i++) {
        if (b[n][i] == '2') {
            cout << cur * 2 << " ";
            cur = cur * 2;
        }
        if (b[n][i] == '1') {
            cout << cur + 1 << " ";
            cur++;
        }
        if (b[n][i] == '3') {
            cout << cur * 3 << " ";
            cur = cur * 3;
        }
    }
}

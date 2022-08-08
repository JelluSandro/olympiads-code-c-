#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 4 == 0) {
            if (x / 4 > 0) {
                cout << x / 4 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            if (x % 4 == 1) {
                if (x / 4 - 1 != 0) {
                    cout << x / 4 - 1 << endl;
                } else {
                    cout << -1 << endl;
                }
            } else {
                if (x % 4 == 2) {
                    if (x / 4 > 0) {
                        cout << x / 4 << endl;
                    } else {
                        cout << -1 << endl;
                    }
                } else {
                    if ((x - 9) / 4 - 1 > 0) {
                        cout << (x - 9) / 4 << endl;
                    } else {
                        cout << -1 << endl;
                    }
                }
            }
        }
    }
}

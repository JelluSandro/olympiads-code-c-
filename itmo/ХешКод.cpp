#include <bits/stdc++.h>
#define ss second
#define ff first
 
using namespace std;
int n;
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i < 500 + 1) {
            for (int j = 0; j < 500; j++) {
                if (j + 1 == i) {
                    cout << "bB";
                } else {
                    cout << "aa";
                }
            }
            cout << "\n";
        } else {
            cout << "bB";
            for (int j = 1; j < 500; j++) {
                if (j == i - 500) {
                    cout << "bB";
                } else {
                    cout << "aa";
                }
            }
            cout << "\n";
        }
    }
}
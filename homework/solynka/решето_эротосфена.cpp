#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n + 1; i++) {
        a[i] = i;
    }
    for (int p = 2; p < n + 1; p++) {
        if (a[p] != 0) {
            for (int i = p * p; i < n + 1; i = i + p) {
                a[i] = 0;
            }
        }
    }
    for (int i = 2; i < n + 1; i++) {
        if (a[i] != 0) {
            cout << a[i] << " ";
        }
    }

}

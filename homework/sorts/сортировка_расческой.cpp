#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double f = 1.2473309;
    int s = n - 1;
    while (s >= 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] > a[i + s])
                swap(a[i], a[i + s]);
        }
        s = s / f;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

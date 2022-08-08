#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    const int mix = 1000;
    int a[mix] = {0};
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a[b]++;
    }
    for (int i = 0; i < mix; i++) {
        while (a[i] > 0) {
            cout << i << " ";
            a[i]--;
        }
    }
}

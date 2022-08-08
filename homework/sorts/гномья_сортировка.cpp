#include <iostream >

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 1, j = 2;
    while (i < n) {
        if (a[i - 1] < a[i]) {
            i = j;
            j++;
        } else {
            swap(a[i - 1], a[i]);
            i--;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

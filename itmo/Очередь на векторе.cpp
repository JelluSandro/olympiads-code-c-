#include <iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int l = 10;
    int g = -1;
    int r = 0;
    int *a = new int[l];
    for (int i = 0; i < n; i++) {
        char s;
        cin >> s;
        if (s == '+') {
            int x;
            cin >> x;
            if (l == g + 1) {
                int *b = new int[l];
                for (int j = 0; j < l; j++) {
                    b[j] = a[j];
                }
                l *= 2;
                a = new int[l];
                for (int j = 0; j < l / 2; j++) {
                    a[j] = b[j];
                }
                g++;
                a[g] = x;
            } else {
                g++;
                a[g] = x;
            }
        } else {
            cout << a[r] << "\n";
            r++;
        }
    }
}
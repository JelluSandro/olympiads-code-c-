#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << "0 1 1\n";
        return 0;
    }
    if (m < 3) {
        cout << "1 1 2\n";
        cout << "0 1 2\n";
    } else if (m == 3) {
        cout << "1 3 2\n";
        cout << "1 3 1\n";
        cout << "0 1 2\n";
    } else {
        m -= 2;
        int cnt = 4;
        cout << "1 3 2\n";
        cout << "1 3 1\n";
        for (; m > 0;) {
            cout << "1 " << cnt << " " << cnt - 1 << "\n";
            m--;
            cnt++;
            for (int i = 1; i + 1 <= cnt; i += 2) {
                if (m == 0) {
                    return 0;
                }
                cout << "0 " << i << " " << i + 1 << "\n";
                m--;
            }
        }
    }
}
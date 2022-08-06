#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("che.in");
    ofstream cout("che.out");
    long long n, r;
    cin >> n >> r;
    long long a[n];
    for (int i = 0; i < n; i++) {

        cin >> a[i];
    }
    long long j = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        while (flag == true) {
            if (j == n)
                break;
            if (a[j] - a[i] > r) {
                cnt = cnt + n - j;
                flag = false;
            } else {
                j++;
            }


        }
    }
    cout << cnt;
}

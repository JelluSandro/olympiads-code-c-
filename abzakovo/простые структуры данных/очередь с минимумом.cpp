#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("queuemin.in");
    ofstream cout("queuemin.out");
    int n;
    cin >> n;
    bool flag1 = true, flag2 = false;
    vector <pair<int, int>> a(n);
    vector <pair<int, int>> b(n);
    int a1 = 0;
    int b1 = 0;
    for (int i = 0; i < n; i++) {
        char gg;
        cin >> gg;
        if (gg == '+') {
            int dd;
            cin >> dd;
            a[a1].first = dd;
            a[a1].second = dd;
            if (a1 - 1 >= 0) {
                a[a1].second = min(a[a1].second, a[a1 - 1].second);
            }
            a1++;
        }
        if (gg == '?') {
            if ((b1 >= 1) && (a1 >= 1))
                cout << min(b[b1 - 1].second, a[a1 - 1].second) << "\n";
            else if (b1 == 0)
                cout << a[a1 - 1].second << "\n";
            else cout << b[b1 - 1].second << "\n";
        }
        if (gg == '-') {

            if (b1 == 0) {


                for (int i = a1 - 1; i >= 1; i--) {

                    b[b1].first = a[i].first;
                    b[b1].second = b[b1].first;
                    if (b1 > 0)
                        b[b1].second = min(b[b1].first, b[b1 - 1].second);

                    b1++;
                }
                a1 = 0;
            } else {
                b1--;
            }
        }
    }
}

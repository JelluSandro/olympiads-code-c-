#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("stack2.in");
    ofstream cout("stack2.out");
    vector<int> a;
    int n;
    cin >> n;
    a.resize(n);
    int s = 0;
    for (int i = 0; i < n; i++) {

        char h;
        cin >> h;
        if (h == '+') {

            int gg;
            cin >> gg;
            a[s] = gg;
            s++;
        } else {
            cout << a[s - 1] << "\n";
            s--;
        }

    }
}

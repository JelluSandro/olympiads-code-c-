#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("queue2.in");
    ofstream cout("queue2.out");
    int n;
    cin >> n;
    vector<int> a(n);
    int lol = 0;
    int kek = 0;
    for (int i = 0; i < n; i++) {
        char gg;
        cin >> gg;
        if (gg == '+') {
            int dd;
            cin >> dd;
            a[kek] = dd;
            kek++;
        } else {
            cout << a[lol] << "\n";
            lol++;
        }


    }
}

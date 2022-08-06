#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    string s;
    cin >> s;
    int ot = 0;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            a++;
        }
        if (s[i] == 'b') {
            b += a;
        }
        if (s[i] == 'c') {
            ot += b;
        }
    }
    cout << ot;
}

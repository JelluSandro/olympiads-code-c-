#include <bits/stdc++.h>

#define int long long
using namespace std;

main() {
    string t;
    cin >> t;
    string pp;
    cin >> pp;
    string s = t + '#' + pp;
    int n = s.size();
    int sz = t.size();
    int p[n];
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int x = p[i - 1];
        while ((x > 0) && (s[i] != s[x])) {
            x = p[x - 1];
        }
        if (s[x] == s[i]) {
            x++;
        }
        p[i] = x;
    }
    vector<int> ot;
    for (int i = 0; i < n; i++) {
        if (p[i] == sz) {
            ot.push_back(i - sz - sz + 1);
        }
    }
    cout << ot.size() << endl;
    for (int i = 0; i < ot.size(); i++) {

        cout << ot[i] << " ";
    }
}

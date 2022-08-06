#include <bits/stdc++.h>

#define int long long
using namespace std;
int p[(int) 1e6 + 10];

main() {
    ios_base::sync_with_stdio(false);
    int md = 1e11 + 7;
    string s;
    cin >> s;
    int a[s.size()];
    int m;
    cin >> m;
    vector<int> ot(m, 0);
    map<int, int> mp;
    p[0] = 1;
    for (int i = 1; i < 1e6 + 10; i++) {
        p[i] = (p[i - 1] * 37) % md;

    }
    for (int ii = 1; ii <= m; ii++) {
        string t;
        cin >> t;
        int x = 0;
        for (int i = 0; i < t.size(); i++) {
            x += ((int) (t[i] - 'a' + 1) * p[i]) % md;
        }
        //cout<<x<<endl;
        mp[x] = ii;
    }
    for (int i = 0; i < s.size(); i++) {
        a[i] = (((int) (s[i] - 'a' + 1))) % md;
    }
    for (int i = 0; i < s.size(); i++) {
        //cout<<i<<" ::;";
        int y = 0;
        int xxx = s.size();
        for (int j = i; j < min(i + 31, xxx); j++) {
            // cout<<i<<" "<<j;
            y += (a[j] * p[j - i]) % md;
            // cout<<" "<<y<<" "<<p[j]<<" "<<a[j]<<" \n";
            //cout<<j<<" "<<i<<endl;
            if (mp.count(y) == 1) {
                ot[mp[y] - 1] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (ot[i] == 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

}

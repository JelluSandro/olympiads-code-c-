#include <bits/stdc++.h>

_Pragma("GCC optimize(\"-0fast\")")
#define int long long
using namespace std;
int md = 1e9 + 7;

vector <vector<int>> gg;
vector <vector<int>> st;

vector <vector<int>> ym(vector <vector<int>> &a, vector <vector<int>> &b) {
    vector <vector<int>> r(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < (int) a.size(); i++) {
        for (int j = 0; j < (int) b[0].size(); j++) {
            for (int k = 0; k < (int) b.size(); k++) {
                r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % md;
            }
        }
    }
    return r;
}

vector <vector<int>> p(vector <vector<int>> &mm, int pp) {
    if (pp == 1) return mm;
    if (pp % 2 == 1) {
        // vector<vector<int> > b = ym(mm, gg);
        // return (p(b, pp - 1));
        vector <vector<int>> b = p(mm, pp - 1);
        return (ym(b, mm));
    } else {
        vector <vector<int>> b = ym(mm, mm);
        return (p(b, pp / 2));
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d, e, n;
    cin >> a >> b >> c >> d >> e >> n;
    if ((n == 1) || (n == 2)) {
        cout << 1;
        return 0;
    }
    gg = {{a, b, c, d, e},
          {1, 0, 0, 0, 0},
          {0, 0, 2, 0, 0},
          {0, 0, 0, 1, 1},
          {0, 0, 0, 0, 1}};
    st = {{1},
          {1},
          {8},
          {3},
          {1}};
    vector <vector<int>> ans = p(gg, n - 2);
    vector <vector<int>> ot = ym(ans, st);
    cout << ot[0][0];
}

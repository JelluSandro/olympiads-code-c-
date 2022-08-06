#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

int const N = 1e4 + 20;
ull MOD = (1e9 + 7);

ull p = 29;
ull C[N];

ull f(char a) {
    return a - 'a' + 1;
}

vector <ull> HASH(string str) {
    vector <ull> result;
    int n = str.size();
    result.resize(str.size() + 1);
    result[1] = f(str[0]) % MOD;
    for (int i = 1; i < n; ++i)
        result[i + 1] = (result[i] + ((C[i] * f(str[i])) % MOD)) % MOD;
    return result;
}

int main() {


    C[0] = 1;
    for (int i = 1; i < N; ++i) C[i] = (C[i - 1] * p) % MOD;


    int n;
    cin >> n;
    vector <string> a(n);
    vector <vector<ull>> info(n);

    int miin = 2e9;
    int mxlen = -2e9;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        miin = min((int) a[i].size(), miin);
        info[i] = HASH(a[i]);
        mxlen = max((int) a[i].size(), mxlen);
    }

    int lo = 0;
    int high = mxlen + 1;

    ull qwerty = -1;

    while (high - lo > 1) {
        int mid = (lo + high) >> 1;

        map <ull, set<ull>> lens;

        for (int i = 0; i < n; ++i) {

            for (int j = 1; j < info[i].size(); ++j) {
                if (j - mid + 1 >= 1) {
                    ull X = (C[N - j] * ((info[i][j] + MOD - info[i][j - mid]) % MOD)) % MOD;
                    lens[X].insert(i);
                }
            }

        }

        ull ans_hash = -1;

        bool yes = 0;
        for (auto i : lens) {
            if (i.second.size() == n) {
                ans_hash = i.first;
                yes = 1;
            }
        }

        if (yes) {
            qwerty = ans_hash;
            lo = mid;
        } else {
            high = mid;
        }
    }

    for (int i = 1; i <= a[0].size(); ++i) {
        if (i - lo + 1 >= 1) {
            ull X = (C[N - i] * ((info[0][i] + MOD - info[0][i - lo])) % MOD) % MOD;

            if (X == qwerty) {
                for (int k = i - lo; k < i; ++k)
                    cout << a[0][k];
                return 0;
            }

        }
    }

}

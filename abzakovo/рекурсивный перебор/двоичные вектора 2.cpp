#include <bits/stdc++.h>

using namespace std;
int m;
int cnt = 0;
vector<int> a;
vector<int> b(100000);
vector<bool> f(10, false);

void fun(int n, int ind) {
    if (ind == n) {
        for (int i = 0; i < n - 1; i++) {
            if ((a[i] == 1) && (a[i + 1] == 1))
                return;
        }
        for (int i = 0; i < n; i++) {
            b[cnt * n + i] = a[i];

        }
        cnt++;
        return;
    }
    for (int i = 0; i < 2; i++) {


        a.push_back(i);
        fun(n, ind + 1);
        a.pop_back();

    }
}

int main() {
    freopen("vectors2.in", "r", stdin);
    freopen("vectors2.out", "w", stdout);
    cin >> m;
    fun(m, 0);
    cout << cnt << "\n";
    for (int i = 0; i < cnt * m; i++) {
        if (i != 0)
            if (i % m == 0)
                cout << "\n";
        cout << b[i];

    }
}

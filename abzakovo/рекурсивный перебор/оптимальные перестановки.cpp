#include <bits/stdc++.h>

using namespace std;
int m;
int r;
int mix = -1;

vector<int> a;
vector<int> b(15);
vector<bool> f(15, false);

void fun(int n, int ind) {
    if (ind == n) {


        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
            cnt = cnt + (a[i] + 1) * (a[i + 1] + 1);
        cnt = cnt % r;
        if (cnt > mix) {

            mix = cnt;
            for (int i = 0; i < n; i++)
                b[i] = a[i] + 1;
        }
        return;
    }
    for (int i = 0; i < n; i++) {

        if (f[i] == false) {
            f[i] = true;
            a.push_back(i);
            fun(n, ind + 1);
            a.pop_back();
            f[i] = false;
        }
    }
}

int main() {
    freopen("optimal.in", "r", stdin);
    freopen("optimal.out", "w", stdout);
    cin >> m >> r;
    fun(m, 0);
    cout << mix << "\n";
    for (int i = 0; i < m; i++) {

        cout << b[i] << " ";
    }

}

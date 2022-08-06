#include <bits/stdc++.h>

using namespace std;
int m;
vector<int> a;
vector<bool> f(10, false);

void fun(int n, int ind) {
    if (ind == n) {
        for (int i = 0; i < n; i++)
            cout << a[i] + 1 << " ";
        cout << "\n";
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
    freopen("permutations.in", "r", stdin);
    freopen("permutations.out", "w", stdout);
    cin >> m;
    fun(m, 0);

}

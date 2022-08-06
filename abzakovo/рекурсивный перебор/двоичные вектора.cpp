#include <bits/stdc++.h>

using namespace std;
int m;
vector<int> a;
vector<bool> f(10, false);

void fun(int n, int ind) {
    if (ind == n) {
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << "\n";
        return;
    }
    for (int i = 0; i < 2; i++) {


        a.push_back(i);
        fun(n, ind + 1);
        a.pop_back();

    }
}

int main() {
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    cin >> m;

    cout << pow(2, m) << "\n";
    fun(m, 0);

}

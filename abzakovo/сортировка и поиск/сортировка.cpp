#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int const mx = 1000099;
int a[mx];

void q(int l, int r) {
    int x = a[rand() % (r - l) + l];
    int i = l;
    int j = r;
    while (i <= j) {
        while (a[i] < x)i++;
        while (a[j] > x)j--;
        if (i <= j) {
            swap(a[i], a[j]);
            {
                i++;
                j--;
            }
        }
    }
    if (i < r) {
        q(i, r);
    }
    if (j > l) {
        q(l, j);
    }
}

int main() {
    ifstream cin("sort.in");
    ofstream cout("sort.out");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    q(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

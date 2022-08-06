#include <bits/stdc++.h>

using namespace std;
int const mix = 1000009;
int n;
int cur = 0;

void mer(vector<int> &b, vector<int> &c, vector<int> &a) {
    int v1 = 0;
    int v2 = 0;
    int v3 = 0;
    while ((v1 < b.size()) && (v2 < c.size())) {

        if (b[v1] < c[v2]) {

            a[v3++] = b[v1++];
        } else {
            cur = cur + b.size() - v1;

            a[v3++] = c[v2++];
        }
    }
    for (int i = v1; i < b.size(); i++)
        a[v3++] = b[i];

    for (int i = v2; i < c.size(); i++)
        a[v3++] = c[i];
}

void f(vector<int> &a) {
    if (a.size() < 2)
        return;
    int l = a.size() / 2;
    int r = a.size() - l;
    vector<int> b(l), c(r);
    for (int i = 0; i < b.size(); i++)
        b[i] = a[i];
    for (int i = 0; i < c.size(); i++)
        c[i] = a[i + b.size()];
    f(b);
    f(c);
    mer(b, c, a);
}

int main() {
    ifstream cin("inverse.in");
    ofstream cout("inverse.out");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    f(a);
    cout << cur;
    return 0;
}

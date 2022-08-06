#include <bits/stdc++.h>

int p, f;
long double a;

long double fun(long double x) {
    long double c = sqrt(x * x + (1 - a) * (1 - a)) / p + sqrt(a * a + (1 - x) * (1 - x)) / f;
    return c;
}

using namespace std;

int main() {
    ifstream cin("forest.in");
    ofstream cout("forest.out");
    cin >> p >> f;
    cin >> a;
    long double l = 0, r = 1;
    for (int i = 0; i < 200; i++) {
        long double m1 = l + (r - l) / 3;
        long double m2 = r - (r - l) / 3;
        long double a1 = fun(m1);
        long double a2 = fun(m2);
        if (a1 > a2)
            l = m1;
        else
            r = m2;
    }
    cout.precision(9);
    cout << fixed << l;

}

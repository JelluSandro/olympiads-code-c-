#include <bits/stdc++.h>

#define ld long double

using namespace std;

int main() {
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << y2 - y1 << " " << x1 - x2 << " " << -(y2 - y1) * x1 - (x1 - x2) * y1;
}

#include <bits/stdc++.h>

#define ld long double

using namespace std;

pair<ld, ld> vtor(ld x1, ld y1, ld x2, ld y2) {
    ld a = x2 - x1;
    ld b = y2 - y1;
    return (make_pair(a, b));
}

ld cosoe(ld a1, ld a2, ld b1, ld b2) {
    ld a = a1 * b2 - a2 * b1;
    return (a);
}

ld scar(ld a1, ld a2, ld b1, ld b2) {
    ld a = a1 * b1 + a2 * b2;
    return (a);
}

pair<pair<ld, ld>, ld> yr(ld x1, ld y1, ld x2, ld y2) {
    ld a = y2 - y1;
    ld b = x1 - x2;
    ld c = -a * x1 - b * y1;
    return (make_pair(make_pair(-a, -b), -c));
}

pair<ld, ld> perpr(ld a1, ld b1, ld c1, ld a2, ld b2, ld c2) {
    ld x = (c2 * b1 - b2 * c1) / (b2 * a1 - a2 * b1);
    ld y = (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1);
    return (make_pair(x, y));
}

ld rast(ld x1, ld y1, ld x2, ld y2) {
    ld r = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return (r);
}

main() {
    int n;
    cin >> n;
    ld s = 0;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        s += x[i] * y[(i + 1) % n];
    }
    for (int i = 0; i < n; i++) {
        s -= x[(i + 1) % n] * y[(i) % n];
    }
    cout << fixed << setprecision(12) << abs(s) / 2;
}

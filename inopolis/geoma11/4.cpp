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
    ld x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    pair<ld, ld> a2 = vtor(x2, y2, x1, y1);
    pair<ld, ld> b2 = vtor(x2, y2, x3, y3);
    pair<ld, ld> a1 = vtor(x3, y3, x1, y1);
    pair<ld, ld> b1 = vtor(x3, y3, x2, y2);
    ld a = scar(a2.first, a2.second, b2.first, b2.second);
    ld b = scar(a1.first, a1.second, b1.first, b1.second);
    if ((a >= 0) && (b >= 0)) {
        ld a1 = cosoe(a2.first, a2.second, b2.first, b2.second);
        ld s = a1 / rast(x2, y2, x3, y3);
        if (s == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
}

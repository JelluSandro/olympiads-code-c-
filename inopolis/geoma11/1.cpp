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
    ld x1, y1, x2, y2, a, b, c;
    cin >> x1 >> y1 >> a >> b >> c;
    ld x01 = 0, y01 = 1, x02 = 1, y02 = 0;
    if (b != 0) {
        y01 = -c / b;
    } else {
        x01 = -c / a;
    }
    if (a != 0) {
        x02 = -c / a;
    } else {
        y02 = -c / b;
    }
    if (c == 0) {
        x01 = 0;
        x02 = 0;
        x02 = 1;
        y02 = 1;
        x02 = (-b) / a;
    }
    pair<ld, ld> a2 = vtor(x01, y01, x1, y1);
    pair<ld, ld> b2 = vtor(x01, y01, x02, y02);
    ld a11 = cosoe(a2.first, a2.second, b2.first, b2.second);
    ld s = a11 / rast(x01, y01, x02, y02);
    cout << fixed << setprecision(12) << abs(s);
}

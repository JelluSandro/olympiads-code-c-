#include <bits/stdc++.h>

#define ld long double

using namespace std;

struct vectr {
    ld xx, yy;
};

ostream &operator<<(ostream &out, const vectr &v) {
    out << v.xx << " " << v.yy;
    return out;
}

istream &operator>>(istream &in, vectr &v) {
    in >> v.xx >> v.yy;
    return in;
}

ld pol(ld x, ld y) {
    ld answer = atan2(y, x);
    return answer;
}

ld dist(ld x1, ld y1, ld x2, ld y2) {
    ld answer = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return answer;
}

vectr new_vector(ld x1, ld y1, ld x2, ld y2) {
    vectr answer = {x2 - x1, y2 - y1};
    return answer;
}

ld scalr(vectr a, vectr b) {
    ld answer = a.xx * b.xx + a.yy * b.yy;
    return answer;
}

ld cosv(vectr a, vectr b) {
    ld answer = a.xx * b.yy - a.yy * b.xx;
    return answer;
}

int main() {
    ld x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    vectr a = new_vector(x1, y1, x2, y2);
    ld f = dist(x1, y1, x2, y2);
    vectr b, c;
    b = {a.xx / f, a.yy / f};
    c = {b.xx * k, b.yy * k};
    cout << a << endl;
    cout << fixed << setprecision(20) << b << endl;
    cout << c << endl;
    cout << a.yy << " " << -1 * a.xx << endl;
    cout << -1 * a.yy << " " << a.xx << endl;
}

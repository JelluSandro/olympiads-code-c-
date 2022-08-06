#include <bits/stdc++.h>

#define ld long double
#define pi 3.14159265358979323

using namespace std;

struct vectr {
    ld xx, yy;
};

ld pol(ld x, ld y) {
    ld answer = atan2(y, x);
    return (answer);
}

ld dist(ld x1, ld y1, ld x2, ld y2) {
    ld answer = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return (answer);
}

vectr new_vector(ld x1, ld y1, ld x2, ld y2) {
    vectr answer = {x2 - x1, y2 - y1};
    return (answer);
}

ld scalr(vectr a, vectr b) {
    ld answer = a.xx * b.xx + a.yy * b.yy;
    return (answer);
}

ld cosv(vectr a, vectr b) {
    ld answer = a.xx * b.yy - a.yy * b.xx;
    return (answer);
}

int main() {
    ld x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cout << fixed << setprecision(7) << dist(x1, y1, x2, y2) << " " << dist(x3, y3, x4, y4) << endl;
    vectr a = new_vector(x1, y1, x2, y2), b = new_vector(x3, y3, x4, y4);
    vectr c = new_vector(0, 0, a.xx + b.xx, a.yy + b.yy);
    cout << fixed << setprecision(7) << c.xx << " " << c.yy << endl;
    cout << fixed << setprecision(7) << scalr(a, b) << " " << cosv(a, b) << endl;
    cout << fixed << setprecision(7) << abs(cosv(a, b)) / 2 << endl;
}

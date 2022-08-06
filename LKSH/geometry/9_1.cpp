#include <bits/stdc++.h>

#define ld long double

using namespace std;

int main() {
    ld x, y;
    cin >> x >> y;
    ld answer = atan2(y, x);
    if (answer < 0) {
        answer += 2 * M_PI;
    }
    cout << fixed << setprecision(20) << answer;
}

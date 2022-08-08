#include <bits/stdc++.h>
using namespace std;
#define long long
main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int n;
    cin >> n;
    int cnt = 0;
    if((n % (a + b)) < a) {
        cnt++;
    }
    if((n % (c + d)) < c) {
        cnt++;
    }
    cout<<cnt;
}
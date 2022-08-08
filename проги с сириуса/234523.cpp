#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//  for(set<int>::iterator it = st.begin(); it!=st.end();it++) {
//      cout << *it <<" "; }
#define int long long
#define ss second
#define ff first
using namespace std;
int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

int r = 0,k = 0, l = 10, m, s,z,t;
int n;
void f2();
void f1();
void f1() {
    if(k < 9) {
        m =0;
        s =0;
        f2();
    } else {
        cout<<r;
    }
}
void f2() {
    if(s < 9) {
        z =( (int)(n/1e5) )%10;
        if(z <m &&z <l) {
            m= z;
            t = s;
        }
        s = s + 1;
        f2();
    } else {
        if(m > 0) {
            r = r + 10 + t;
            k = k + 1;
            l = m;
            f1();
        } else {
            f1();
        }
    }
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>> n;
    f1();
}


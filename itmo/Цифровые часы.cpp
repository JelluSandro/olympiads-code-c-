#include <bits/stdc++.h>
using namespace std;
#define long long
vector < int > a(10);
int ff(int b){
    int ans = 0;
    if(b < 10) {
        ans+=6;
    } else {
        ans += a[b/10];
    }
    ans+= a[b%10];
    return ans;
}
main() {
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    a[0] = 6;
    a[1] = 2;
    a[2] = 5;
    a[3] = 5;
    a[4] = 4;
    a[5] = 5;
    a[6] = 6;
    a[7] = 3;
    a[8] = 7;
    a[9] = 6;
    for(int i =0; i< 24;i++) {
        for(int j =0;j < 60;j++) {
            if(ff(i) + ff(j) == n) {
                if(i < 10) {
                    cout<<"0";
                }
                cout<<i<<":";
                if(j < 10) {
                    cout<<"0";
                }
                cout<<j;
                return 0;
            }
        }
    }
    cout<<"Impossible";
}
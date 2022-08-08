#include <bits/stdc++.h>
 
#define int long long
#define ss second
#define mp make_pair
#define ld long double
 
using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int mn =13000;
    int mx = 0;
    for(int i =0;i < 30;i++) {
        for(int j = 0;j < 30;j ++) {
            for(int k =0;k < 30;k++) {
                if(i * 12 + j * 16 + k*15 == 326) {
                   
                    int cost = 400 * i + 500 * j + 600 * k;
                     cout << i <<" " << j << " " << k <<" :  " <<cost<<"\n";
                    mn = min(mn, cost);
                    mx = max(mx, cost);
                }
            }
        }
    }
    cout <<mn <<"  "<<mx;
}

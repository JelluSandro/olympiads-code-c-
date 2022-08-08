#include <bits/stdc++.h>
using namespace std;
#define long long
main() {
    int n;
    cin >> n;
    int cnt = 0;
    int mx = 0;
    vector <pair <pair <string, string>, int > > a(n); 
    for(int i=0;i<n;i++) {
        cin >> a[i].first.first >> a[i].first.second;
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        cnt = a1+a2+a3;
        a[i].second = cnt;
        mx = max(mx, cnt);
    }
    double x = mx;
    cout<<x/3<<"\n";
    for(int i =0;i <n;i++) {
        if(a[i].second == mx) {
            cout<<a[i].first.first <<" "<<a[i].first.second<<"\n";
        }
    }
     
     
}
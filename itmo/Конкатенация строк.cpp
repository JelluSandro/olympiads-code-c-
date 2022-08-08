#include <bits/stdc++.h>
using namespace std;
#define long long
main() {
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    string t = "";
    int n = s.size();
    for(int i =0;i < n;i++) {
        if(s[i] == '(') {
            int j = i + 1;
            string k = "";
            for(;j < n;j++) {
                if(s[j] ==')') {
                    break;
                } else {
                    k= k + s[j];
                }
            }
            i = j;
            reverse(k.begin(),k.end());
            t = t + k;
        } else {
            t= t + s[i];
        }
    }
    cout<<t;
}
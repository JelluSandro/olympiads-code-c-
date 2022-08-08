#include <bits/stdc++.h>
using namespace std;
#define long long
main() {
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    string s[m];
    for(int i= 0;i < m; i++) {
        cin>> s[i];
    }
    int n = s[0].size();
    vector < int > p(n, 0);
    for(int i =0; i < n - 1;) {
        for(int j =0 ;j < m; j++) {
            for(int k = 0;k < n;k++) {
                if(p[(int)s[j][k] - '0'] != -1) {
                    p[(int)s[j][k] - '0']++;
                    break;
                }
            }
        }   
        int mn = 1e9;
        for(int j =0;j < n;j++) {
            if(p[j] == -1) {
                continue;
            }
            mn = min(mn, p[j]);
        }
        int cnt = 0;
        for(int j = 0;j < n;j++) {
            if(p[j] == -1) { continue;}
            if(p[j] == mn) {
                p[j] = -1;
                cnt++;
            } else {
                p[j] = 0;
            }
        }
        i+=cnt;
    }
    int cnt = -1;
    for(int i =0;i < n;i++) {
        if(p[i] != -1) {
            cnt = i;
        }
    }
    cout<<cnt;
}
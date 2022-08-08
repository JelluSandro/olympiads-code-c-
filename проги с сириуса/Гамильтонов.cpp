#include <bits/stdc++.h>
 
using namespace std;
#define int long long
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    long long g[20][20];
    long long INF = 2e13;
    cin>>n>>m;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            g[i][j] = INF;
        }
    }
    for(int i=0;i<m;i++){
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        a1--;
        a2--;
        g[a1][a2]=a3;
        g[a2][a1]=a3;
    }
         
    int x = 1<<n;
    long long dp[n][x];
        for(int i=0;i<n;i++){
        for(int j=0;j<x;j++){
            dp[i][j]=INF;
        }
    }
        for(int j=0;j<x;j++){
                for(int i=0;i<n;i++){
            if((j&(1<<i))==0){
                if(j==0){
                    dp[i][j]=0;
                } else {
                    for(int k=0;k<n;k++){
                        if((j&(1<<k))==(1<<k)){
                            dp[i][j] = min(dp[i][j], dp[k][j^(1<<k)]+g[i][k]);
                        }
                    }
                }
            }
        }
    }
 
    int x1 = x - 1;
    long long cnt = INF;
    for(int i=0;i<n;i++){
        cnt = min(cnt,dp[i][(x1^(1<<i))]);
    }
    if(cnt >= INF){
        cout<<-1;
        return 0;
    }
    cout<<cnt;
}

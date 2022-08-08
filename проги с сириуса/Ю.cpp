#include <bits/stdc++.h>
 
using namespace std;
#define int long long

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    char a[n][2*n-1];
    for(int i=0;i<n;i++){
    for(int j=0;j<2*n-1;j++){
    	a[i][j]='.';
	}	
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		a[i][n-1]='*';
    	for(int j=n;j<n+cnt;j++){
    		a[i][j]='*';
		}
		    for(int j=n-1;j>n-cnt-2;j--){
    		a[i][j]='*';
		}		
		cnt++;
	}
	for(int i=0;i<n;i++){
    for(int j=0;j<2*n-1;j++){
    	cout<<a[i][j];
	}	
	cout<<endl;
	}
}

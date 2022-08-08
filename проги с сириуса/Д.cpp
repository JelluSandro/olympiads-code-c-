#include <bits/stdc++.h>
 
using namespace std;
#define int long long

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  	int n,k;
  	cin>>n>>k;
  	vector < int > ans;
  	for(int i=1;i*i<=n;i++){
  		if(n%i==0){
  			int y = n/i;
  			int x1 = y*k, x2 = y*k + k - 1;
  			if(i < k){
  				 ans.push_back(x1 + i);
			  }
			  if(y < k){
  				 ans.push_back(k*i + y);
			  }
			 
		  }
	  }
	  sort(ans.begin(),ans.end());
	  cout<<ans[0];
}



#include <bits/stdc++.h>

#define int long long
using namespace std;
main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin>>n>>t;
    vector < pair < int , int  >  > a;
    for(int i=0;i<n;i++){
    	int a1,a2;
    	cin>>a1>>a2;
    	a.push_back({a1, a2 });
    	a.push_back({a2, -1 });
	}
	sort(a.begin(),a.end());
	vector < int > pr(2*n,0);
	vector < int > yx(2*n,0);
	for(int i=0;i<2*n;i++){
		if(i!=0){
			pr[i] = pr[i-1];
			yx[i] = yx[i-1];
		}
		if(a[i].second == -1){
			yx[i]++;
		} else {
			pr[i]++;
		}
	}
	int ans = 0;
	int cnt = 0;
    int cur = 0;
    int fin = -1;
    for(int i = 0;i<2*n;i++){
    	if((i!=0)&&(a[i]==a[i-1])){
    		if(a[i].second != -1) {
	    		if(a[i].second <= a[i].first + t - 1) {
    				cnt--;
				}	else {
					cur--;
				}	
			} 
    		continue;
		}
    	fin = max(fin, i-1);
    	for(int j = fin +1;j<2*n;j++) {
    	//	cout<<a[j].first << " "<< a[i].first + t - 1 << ' ' <<j<<endl;
    		fin = j ;
    		if(a[j].first > a[i].first + t - 1) {
    			fin = j-1;
    			break;
			}
			if(a[j].second != -1) {
	    		if(a[j].second <= a[i].first + t - 1) {
    				cnt++;
				}	else {
					cur++;
				}	
			} 
		}
		//cout<<cnt << " "<<fin<<" "<<pr[fin] << " "<<yx[fin]<< " "<<cur<<endl;
		int kol = pr[fin] - yx[fin] - cur;
		ans = max(ans, cnt - kol);
		if(a[i].second != -1) {
	    		if(a[i].second <= a[i].first + t - 1) {
    				cnt--;
				}	else {
					cur--;
				}	
			} 
	}
	cout<<ans;
}

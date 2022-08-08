#include <bits/stdc++.h>
 
using namespace std;
#define int long long
int f(int x){
	int y = 1;
	while( true )  {
		if((x==0)){
			break;
		}
		y = y * (x%10);
		x/=10;
	}
	return (y);
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin >> s >> t;
    int n1 = s.size();
    int n2 = t.size();
    string h = "";
    int st = 0;
    if(n1 == n2) {
    	for(int i=0;i<n1;i++){
    		if(s[i] == t[i]){
    			h = h + s[i];
    			st++;
			} else {
				break;
			}
		}
	}
	if(st == n2){
		cout<<s;
		return 0;
	}
	int xx = min(n2 - st,7LL);
  	int l= 1,r = 0;
  	for(int i=1;i<xx;i++){
  		l = l * 10;
	  }
   	for(int i = st ;i<min(n2,st+7);i++){
   		r = r*10 + ((int)t[i]-'0');
	}
	bool ff = 0;
	for(int i=n2-1;i>=min(n2,st+7);i--){
		if(t[i]-'0'!=9){
			ff=1;
		}
	}
	if(ff==0){
		r++;
	}
   	int mx =-1 , ans =r;
   	for(int i = l; i <r ;i++){
   		int  g = f(i);
   		if(g>mx){
   			mx = g;
   			ans = i;
		}
	}
	cout<<h<<ans;
	if(mx!=-1) {
		for(int i = min(n2,st+7);i<n2;i++){
				cout<<9;
	 	} 
    } else {
    	for(int i = min(n2,st+7) ;i<n2;i++){
				cout<<t[i];
	 	}
	}
	return 0;
}

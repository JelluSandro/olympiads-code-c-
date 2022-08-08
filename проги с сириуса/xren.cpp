#include <bits/stdc++.h>
    
using namespace std;
#define int long long
#define f first
#define s second
int f(int x){
	int y = 1;
	while( true )  {
		if((x==1)||(x==0)){
			break;
		}
		y = y * (x%10);
		x/=10;
	}
	return (y);
}
main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("conveyor.in","r",stdin);
    //freopen("conveyor.out","w",stdout);
    for(int i=10;i<10000;i++){
    	int mx = -1 , ans =0;
    	for(int j = 0; j <= i ;j++){
    		int  g = f(j);
    		if(g>mx){
    			mx = g;
    			ans = j;
			}
		}
    	int x = i;
    	int o = i;
    	int p = 1;
    	int cnt =0;
    	while( true )  {
			if((o==0)){
				break;
			}
			p = p * 10;
			o/=10;
			cnt++;
		} 
		p/=10;
    	int g = i/p - 1;
    	for(int j=0;j<cnt-1;j++){
    		g = g*10 + 9;
		}
		int pp = f(g);
		if(mx>pp){
			cout<<i<<" "<<ans<<" "<<pp<<" "<<g<<endl;
		}
	}
}

#include <bits/stdc++.h>
    
using namespace std;
#define f first
#define s second
vector < int > a;
vector < vector < int >  > g;
vector < int > u;
int  n,m;
vector < int > lol,lal;
void dfs( int v){
	lol.push_back(v);
	lal.push_back(a[v]);
	u[v] = 1;
	for(int i =0;i<g[v].size();i++){
		int to = g[v][i];
		if(u[to]==0){
			dfs(to);
		}
	}
}    
main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("conveyor.in","r",stdin);
    //freopen("conveyor.out","w",stdout);
    cin>>n>>m;
    a.resize(n);
    u.resize(n,0);
    g.resize(n);    
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int a1,a2;
		cin>>a1>>a2;
		a1--;
		a2--;
		g[a1].push_back(a2);
		g[a2].push_back(a1);
	}
	int y=0;
	map < int ,int > mp;
	vector < vector< int  > > gg;
	for(int i=0;i<n;i++){
		if(u[i]==0){
			dfs(i);
			sort(lol.begin(),lol.end());
			sort(lal.begin(),lal.end());
			reverse(lal.begin(),lal.end());
			gg.push_back(lal);		
			for(int i=0;i<lol.size();i++){
				mp[lol[i]] = y;
			}
			y++;
			lol.clear();
			lal.clear();
		}
	}
	vector < int > dp (n+2, 1e9);
	dp[0] = -1e9;
	for (int i=0; i<n; i++) {
		int kk = mp[i];
		for(int k = 0; k < gg[kk].size(); k++) { 
			int to = gg[kk][k];
			int j = int (upper_bound (dp.begin(), dp.end(), to) - dp.begin());
			if (dp[j-1] < to && to < dp[j]) {
				dp[j] = to;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n+2;i++){
		if(dp[i] != 1e9){
			ans = i;
		} else {
			break;
		}
	}
	cout<<ans;
}

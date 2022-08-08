#include <bits/stdc++.h>
    
using namespace std;
#define int long long
#define f first
#define s second
int n,m;
vector < vector < int > > a;
int x = -1;
vector < int> color;
bool fl = 0;
void dfs(int v, int t){
//	cout<<v<<endl;
	color[v] = t;
	t = 2 - (t + 1) % 2;
	for(int i=0;i<a[v].size();i++){
		int to = a[v][i];
		if(to == x) { continue;		}
		//cout<<to<<endl;
		if(color[to]==color[v]){
			fl = 1;
			return;
		} else {
			if(color[to] == 0) {
				dfs(to,t);
			}
		}
	}
}
main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("conveyor.in","r",stdin);
    //freopen("conveyor.out","w",stdout);
    cin>> n >> m;
    a.resize(n);
    color.resize(n,0);
    for(int i=0;i<m;i++) {
    	int a1,a2;
    	cin>>a1>>a2;
    	a1--;
    	a2--;
    	a[a1].push_back(a2);
    	a[a2].push_back(a1);
	}
	vector < int > ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			color[j] =0;
		}
		x =i;
		fl = 0;
		for(int j=0;j<n;j++){
			if((color[j] == 0)&&(j!=x)){
				dfs(j,1);
			}
		}
	//	cout<<fl<< " "<<i<<endl;
		if(fl ==0){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(int i = 0;i<ans.size();i++){
		cout<<ans[i]+1<<" ";
	}
}

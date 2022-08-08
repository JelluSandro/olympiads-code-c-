#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;
int n;
vector < vector < int >  > gr;
int u1=-1,u2 =-1;
void dfs(int v, int pr){
	if(gr[v].size() == 1){
		if(u1 == -1){
			u1 = v;
		} else {
			u2 = v;
		}
	}
	for(int i =0;i < (int)gr[v].size();i++){
		int to = gr[v][i];
		if(to!=pr&&u2==-1){
			dfs(to,v);
		}
	}
}
main() {
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	gr.resize(n);
	vector < int > a(n,0);
	vector < int > ar1(n),ar2(n);
	vector < long double > ar3(n);
	for(int i =0;i<n-1;i++){
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		a1--;
		a2--;
		a[a1]++;
		a[a2]++;
		gr[a1].push_back(a2);
		gr[a2].push_back(a1);
		ar1[i] = a1;
		ar2[i] = a2;
		ar3[i] = a3; 
	}
	bool flag =0;
	for(int i =0;i<n;i++){
		if(a[i] == 2){
			flag = 1;
		}
	}
	if(flag == 0){
		cout<<"YES\n";
		vector < pair < pair < int ,int > , long double > > ans;
		for(int  i =0;i<n -1;i++){
			if(a[ar1[i]]>2){
				u1 = -1;
				u2 = -1;
				dfs(ar1[i],ar2[i]);
				if(u1==-1){
					ans.push_back({{ar2[i],ar1[i]},ar3[i]});
				} else {
					ans.push_back({{ar2[i],u1},ar3[i]/2});
					ans.push_back({{ar2[i],u2},ar3[i]/2});
					ans.push_back({{u2,u1},-ar3[i]/2});
				}
			} else {
				u1 = -1;
				u2 = -1;
				dfs(ar2[i],ar1[i]);
				if(u1==-1){
					ans.push_back({{ar2[i],ar1[i]},ar3[i]});
				} else {
					ans.push_back({{ar1[i],u1},ar3[i]/2});
					ans.push_back({{ar1[i],u2},ar3[i]/2});
					ans.push_back({{u2,u1},-ar3[i]/2});
				}
			}		
		//	cout<<u1<<" "<<u2<<endl;		
		}
		cout<<ans.size()<<'\n';
		for(int i =0;i<ans.size();i++){
			cout<<ans[i].first.first +1<<" "<<ans[i].first.second+1<<" "<<ans[i].second<<"\n";
		}
	} else {
		cout<<"NO\n";
	}
}

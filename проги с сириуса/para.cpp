#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ff first
#define ss second
#define forin(i, n) for(int i =0;i<n;i++)
#define forout(i, n) for(int i =n -1;i>=0;i--)
#define intin(n) int n;cin>>n;
#define ld long double
#define en "\n"
long long INF = 1e18 + 7;
long double EPS = 0.000001;
//set<int>::iterator it = st.begin();it!=st.end();it++
//cout<<fixed<<setprecision(10)<<l;
//memset(dp,-1,sizeof(dp));
//ios_base::sync_with_stdio(false);
int gcd(int a,int b){
	while(b){
		a = a%b;
		swap(a,b);
	}
	return(a);	
}
bool cmp(int a,int b){
	if(a<b){
		return 1;
	} else {
		return 0;
	}
}
int binpow(int a, int n, int md) {
	if(n == 0) { return(1);	}
	if(n%2 == 1) { return((binpow(a,n-1,md)*a)%md);	}
	if(n%2 == 0) {
		int b = binpow(a,n/2,md);
		return((b*b)%md);
	}
}
/*
vector<int> u;
int n;
vector<int> ans;
vector<vector<pair<int, int> > > rb;

void dfs(int v) {
    while (rb[v].size()) {
        if (u[rb[v].back().ss] == 0) {
            u[rb[v].back().ss] = 1;
            int to = rb[v].back().ff;
            rb[v].pop_back();
            dfs(to);
        } else {
            rb[v].pop_back();
        }
    }
    ans.push_back(v);
}

void solve() {
    cin >> n;
    rb.resize(n);
    int x = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (m % 2 == 1) {
            x = i;
        }
        for (int j = 0; j < m; j++) {
            int a1;
            cin >> a1;
            a1--;
            if (i <= a1) {
                rb[i].push_back({a1, cnt});
                rb[a1].push_back({i, cnt});
                cnt++;
            }
        }
    }
    u.resize(cnt, 0);
    dfs(x);
    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
}
*/
/*
int dp[111][111];
int pr[111][111];
int reb[111][111];
int check[111][111];
void floyd(){
	for(int i =0;i<111;i++){
		for(int j = 0;j<111;j++){
			dp[i][j] = -INF;
			pr[i][j] = -1;
			reb[i][j] = -1;
		} 
	}
	int n,m,kk;
	cin>>n>>m>>kk;
	for(int i =0;i<m;i++){
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		a1--;
		a2--;
		if(a3 > dp[a1][a2]){
			dp[a1][a2] = a3;
			reb[a1][a2] = i+1;
			pr[a1][a2] = a2;
		}
	}
	for(int k =0;k<n;k++){
		for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(dp[i][k]!=-INF && dp[k][j]!=-INF && dp[i][j]<dp[i][k] + dp[k][j] && INF>dp[i][k] + dp[k][j]){
					dp[i][j] = dp[i][k] + dp[k][j];
					pr[i][j] = pr[i][k];
				}
			}
		}
	}
	
	for(int i =0;i<111;i++){
		for(int j = 0;j<111;j++){
			check[i][j] = dp[i][j];
		}
	}
	for(int k =0;k<n;k++){
		for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(check[i][k]!=-INF&&check[k][j]!=-INF&&check[i][j]<check[i][k] + check[k][j]){
					check[i][j] = check[i][k] + check[k][j];
				}
			}
		}
	}
	for(int i =0;i<111;i++){
		for(int j = 0;j<111;j++){
			if(check[i][j] != dp[i][j]){
				check[i][j] = 1e9;
			}
		}
	}
	for(int k =0;k<n;k++){
		for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(check[i][k]!=-INF&&check[k][j]!=-INF&&check[i][j]<check[i][k] + check[k][j]){
					check[i][j] = check[i][k] + check[k][j];
				}
			}
		}
	}
	vector < int > ar(kk);
	for(int i =0;i<kk;i++){
		cin>>ar[i];
	}
	for(int i =1;i<kk;i++){
		if(check[ar[i-1] -1][ar[i] -1]!=dp[ar[i-1]-1][ar[i]-1]){
			cout<<"infinitely kind";
			return;
		}
	}
	vector < int > ans;
	for(int i = 1; i < kk; i++){
		//find_root(ar[i-1] - 1,ar[i] - 1);
		int xx = ar[i-1] - 1;
		int yy = ar[i] -1;
    	while (xx != yy) {
    		//cout<<xx<<endl;
       		ans.push_back(reb[xx][pr[xx][yy]]);
        	xx = pr[xx][yy];
    	}
	}
	cout<<ans.size()<<"\n";
	for(int i =0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}
*/
/*
vector < vector < int > > graf;
vector < vector < int > > reb;
vector < int > u;
vector < int > ans;
vector < int > tin;
vector < int > up;
int tim = 1;
int n,m;
void dfs(int v,int p = -1){
	u[v]  = 1;
	tin[v] = tim;
	up[v] = tim;
	tim++;
	for(int i =0;i<graf[v].size();i++){
		int to = graf[v][i];
		if(to == p)  continue;
		if(u[to] == 1 ){
			up[v] = min(up[v],tin[to]);
		} else {
			dfs(to,v);
			up[v] = min(up[v],up[to]);
			if(tin[v] < up[to]){
				ans.push_back(reb[v][i]);
			}
		}
	}	
} 
void most_search(){
	cin>>n>>m;
	graf.resize(n);
	u.resize(n,0);
	tin.resize(n);
	up.resize(n);
	reb.resize(n);
	for(int i =0;i<m;i++){
		int a1,a2;
		cin>>a1>>a2;
		a1--;
		a2--;
		graf[a1].push_back(a2);
		graf[a2].push_back(a1);
		reb[a1].push_back(i+1);
		reb[a2].push_back(i+1);
	}
	for(int i =0;i<n;i++){
		if(u[i] == 0){
			dfs(i, -1);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(int  i=0;i < ans.size();i++){
		cout<<ans[i]<<" ";
	}
}
*/
/*
int n,m;
vector < vector < int > > graf;
vector < int > u;
vector < int > tin;
vector < int > fup;
int tim = 1;
set < int >  ans;
void dfs(int v,int p =-1){
	u[v] = 1;
	tin[v] = tim;
	fup[v] = tim;
	tim++;
	int child = 0;
	for(int i =0;i<graf[v].size();i++){
		int to = graf[v][i];
		if(to == p) { continue;		}
		if(u[to] == 1){
			fup[v] = min(fup[v],tin[to]);
		} else {
			dfs(to,v);
			child++;
			fup[v] = min(fup[v],fup[to]);
			if(tin[v]<=fup[to] && p != -1){
				ans.insert(v);
			}
		}
	}
	if(child>1 && p == -1 ){
		ans.insert(v);
	}
}
void soch_search(){
	cin>>n>>m;
	graf.resize(n);
	u.resize(n);
	tin.resize(n);
	fup.resize(n);
	for(int i =0;i<m;i++){
		int a1,a2;
		cin>>a1>>a2;
		a1--;
		a2--;
		graf[a1].push_back(a2);
		graf[a2].push_back(a1);
	}
	for(int i =0;i<n;i++){
		if(u[i] == 0){
			dfs(i);
		}
	} 
	cout<<ans.size()<<"\n";
	for(set<int>::iterator it = ans.begin();it != ans.end();it++){
		cout<<*it + 1<<"\n";
	}
}
*/
/*
int n,m;
vector < vector < int > > graf;
vector < int > u;
vector < int > tin;
vector < int > out;
int tim = 1;
void dfs(int v){
	u[v]  =1 ;
	tin[v] = tim;
	tim++;
	for(int  i=0;i<graf[v].size();i++){
		int to = graf[v][i];
		if(u[to] == 0){
			dfs(to);
		}
	}
	out[v] = tim;
	tim++;
}
void predok(){
	cin>>n;
	graf.resize(n);
	u.resize(n,0);
	tin.resize(n);
	out.resize(n);
	int s = 0;
	for(int i =0 ; i< n;i++){
		int a1;
		cin>>a1;
		a1--;
		if(a1 == -1){
			s = i;
		} else {
			graf[a1].push_back(i);
			graf[i].push_back(a1);
		}
	}
	dfs(s);
	int m;
	cin>>m;
	for(int i =0;i<m;i++){
		int a1,a2;
		cin>>a1>>a2;
		a1--;
		a2--;
		if(tin[a1]<tin[a2]&&out[a1]>out[a2]){
			cout<<1<<"\n";
		} else {
			cout<<0<<"\n";
		}
	}
}
*/
/*
int n,m;
vector < vector < int > > graf ;
vector < int > u;
vector < int > pr;
void dfs(int v){
	u[v] = 1;
	for(int i = 0;i<graf[v].size();i++){
		int to = graf[v][i];
		if(u[to] == 0){
			pr[to] = v;
			dfs(to);
		} else if (u[to] == 1 ) {			
			vector < int > ans;
			int  p = v;
			for(;;){
				ans.push_back(p);
				if(p == to){
					break;
				}
				p = pr[p];
			}
			cout<<"YES\n";
			reverse(ans.begin(),ans.end());
			for(int i =0;i<ans.size();i++){
				cout<<ans[i] + 1<<" ";
			}
			exit(0);
		}
	}
	u[v] = 2;
}
void cycle(){
	cin>>n>>m;
	graf.resize(n);
	u.resize(n,0);
	pr.resize(n,-1);
	for(int i =0;i<m;i++){
		int a1,a2;
		cin>>a1>>a2;
		a1--;
		a2--;
		graf[a1].push_back(a2);
	}
	for(int i =0;i<n;i++){
		if(u[i] == 0){
			dfs(i);
		}
	}
	cout<<"NO";
}
*/
/*
struct reb{
	int v,u;
};
int n,m;
vector < vector < int > > graf;
vector < vector < int > > gin;
vector < int > u;
vector < int > tp;
int color = 1;
void topsort(int v){
	u[v] = 1;
	for(int i =0;i<graf[v].size();i++){
		int to = graf[v][i];
		if(u[to] == 0){
			topsort(to);
		}
	}
	tp.push_back(v);
}
void dfs(int v){
	u[v] = color;
	for(int i =0;i<gin[v].size();i++){
		int to = gin[v][i];
		if(u[to] == 0){
			dfs(to);
		}
	}
}
void condence(){
	cin>>n>>m;
	graf.resize(n);
	gin.resize(n);
	u.resize(n,0);
	vector < reb > rb(m);
	for(int i =0;i<m;i++){
		int a1,a2;
		cin>>a1>>a2;
		a1--;
		a2--;
		rb[i].v = a1;
		rb[i].u = a2;
 		graf[a1].push_back(a2);
		gin[a2].push_back(a1);
	}
	for(int i =0;i<n;i++){
		if(u[i] == 0){
			topsort(i);
		}
	}
	for(int i =0;i<n;i++){
		u[i] = 0;
	}
	reverse(tp.begin(),tp.end());
	for(int i =0;i<n;i++){
		int to  = tp[i];
		if(u[to] == 0){
			dfs(to);
			color++;
		}
	}
	set < pair < int , int >  > st;
	for(int i =0;i<m;i++){
		if(u[rb[i].v]!=u[rb[i].u]){
			st.insert({u[rb[i].v],u[rb[i].u]});
		}
	}
	cout<<st.size()<<"\n";
}
*/
void solve(){
	int n,k;
	cin>>n>>k;
	multiset < int > st;
	vector < int > a(n);
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	if(k - 1>0){
	for(int i =1;i<n;i++){
		int x = (a[i] - a[i-1]);
		if(st.size()<k-1){
			st.insert(x);
		} else {
				int y = *st.begin();
				if(y<x){
					st.erase(st.begin());
					st.insert(x);
				}
		}
	}
}
	int sum = 0;
	for(set<int>::iterator it = st.begin();it!=st.end();it++){
		sum+=*it;
	}
	cout<<a[n-1] - a[0] - sum;
}
main(){
//	freopen("condense2.in","r",stdin);
//	freopen("condense2.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

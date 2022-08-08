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

void solve(){
	int n,m;
	cin>>n;
	cout<<"l:OL"<<endl;
	vector < int > a(n);
	for(int  i =0;i<n;i++){
		cin>>a[i];
	}
	cout<<"lOL";
	cin>>m;
	vector < int > b(m);
	for(int i =0;i<m;i++){
		cin>>b[i];
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	cout<<a[0]<<" "<<b[0];
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

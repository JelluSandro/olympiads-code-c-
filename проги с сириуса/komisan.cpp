#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second
#define forin for(int i =0;i<n;i++)
#define forout for(int i =n -1;i>=0;i--)
#define intn int n; cin>>n;
#define ld long double
long long INF = 1e18 + 7;
long double EPS = 0.000001;
//set<int>::iterator it = st.begin();it!=st.end();it++
//cout<<fixed<<setprecision(10)<<l;
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
int md = 998244353;
main(){
	int n;
	cin>>n;
	vector < int > a(n);
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	int ans = 0;
	vector < int > b(18);
	vector < int > b1(18);
	b[0] = n;
	for(int i =0;i<n;i++){
		int  kk  = 1;
		int kk1 = 10;
		int cnt = 0;
		int o = a[i];
		for(;;){
			if(a[i] == 0) { break;	}
			a[i] =a[i]/10;
			kk= (kk*100)%md;
			cnt++;
			b[cnt] = (b[cnt]+kk)%md;
			b1[cnt - 1] = (b1[cnt - 1]+kk1)%md;
			if(a[i]!=0)
			kk1 = (kk1*100)%md;
		}
		cnt++;
		for(;cnt<18;cnt++){
			kk = (kk*10)%md;
			kk1 = (kk1*10)%md;
			b[cnt]= (b[cnt]+kk)%md;
			b1[cnt -1]= (b1[cnt -1]+kk1)%md;
		}
		a[i] = o;
	}
	for(int i =0;i<n;i++){
		int cnt =0;
		int  o = a[i];
		for(;;){
			if(a[i] == 0) { break;	}
			int x = a[i]%10;
			a[i] =a[i]/10;
			 x = (x*b[cnt])%md;
			ans = (ans + x)%md;
			cnt++;
		}
		a[i] = o;
	}
	for(int i =0;i<n;i++){
		int cnt =0;
		int  o = a[i];
		for(;;){
			if(a[i] == 0) { break;	}
			int x = a[i]%10;
			a[i] =a[i]/10;
			 x = (x*b1[cnt])%md;
			ans = (ans + x)%md;
			cnt++;
		}
		a[i] = o;
	}
	cout<<ans<<" ";
}


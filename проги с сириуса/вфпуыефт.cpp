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
int cnt =0;
main(){
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>q;
	for(int ii =0;ii<q;ii++){
		string s;
		cin>>s;
		int n = s.size();
		vector < int > p(n,0);
		int cc =0;
		for(int i =0;i<n;i++){
			p[i] = cc;
			if(s[i] == '0'){
				cc++;
			} else {
				cc = 0;
			}
		}
		deque < pair < int , int > > d;
		for(int i =0;i<n;i++){
			vector < pair < int ,  int >  > a;
			while(d.size() > 0) {
				int x = ((d.front().ss)<<1) + (s[i] -'0');
				if(x>(d.front().ff + 1)){
					d.pop_front();
				} else {
					a.push_back({d.front().ff + 1,x});
					if(x <= d.front().ff + 1) {
						cnt++;
					} 
					d.pop_front();
				}
			}
			for(int j =0;j<a.size();j++){
				d.push_back(a[j]);
				//cout<<a[j].first<<endl;
			}
			if(s[i] =='1')
			d.push_back({1 + p[i],(s[i] - '0')});
			if(s[i] == '1'){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
		cnt =0;
	}	
}

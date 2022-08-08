#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
#define mp make_pair
int n, k;
int INF = 1e18;
int const md = 1e6;
vector < vector < pair < int , int > > > g;
vector < vector < int > >  gg;
deque < pair < vector < pair < int ,int > >, pair < int , pair < int , int > > > > d;
int cur = INF;

void merge(vector < pair < int ,int > > &a, vector < pair < int ,int > > b) {
	for(int i =0;i < k; ++i) {
		int x1 = a[i].ff;
		int x2 = b[i].ff;
		int x3 = a[i].ss;
		int x4 = b[i].ss;
		int x5 = max(x1, x2);
		int x6 = min(x3, x4);
		if(x5 > x6) {
			a[i].ff = INF;
		}  else {
			a[i].ff = x5;
			a[i].ss = x6;
		}
	} 
}

void bfs(int v, int pr, int  cnt, vector < pair < int , int > > h) {
	//cout << v << "!!"<<endl;
	for(int i =0;i < gg[v].size(); ++i) {
		int to = gg[v][i];
		if(to == pr) {
			continue;
		}
		vector < pair < int , int > > hh = h;
		merge(*&hh, g[to]);
		bool fg = 0;
		for(int j =0;j < k;j++) {
			if(hh[j].ff == INF) {
				fg = 1;
				break;
			}
		}
		
		if(fg == 1) {
			cur = min(cur, cnt + 1);
			return;
		}
		if(cnt + 1 < cur) {
			d.push_back(mp(hh,mp(to, mp(v, cnt + 1))));
		}
	}
}

void solve() {
	cin >> n >> k;
	g.resize(n);
	gg.resize(n);
	for(int i = 0; i < n; ++i) {
		vector < int > a1(k);
		for(int j =0; j < k; ++j) {
			cin >> a1[j];
		}
		for(int j =0; j < k; ++j) {
			int a2;
			cin >> a2;
			if(a2 < a1[j]) {
				swap(a2, a1[j]);
			}
			g[i].push_back(mp(a1[j], a2));
		}
	} 
	
	for(int i = 0; i < n - 1; ++i) {
		int a1, a2;
		cin >> a1 >> a2;
		a1--;
		a2--;
		gg[a1].push_back(a2);
		gg[a2].push_back(a1);
	}
	
	for(int i = 0; i < n; ++i) {
		d.push_back(mp(g[i], mp(i, mp(-1, 1))));
	//	cur = INF;
		while((int)d.size() > 0) {
			bfs(d.front().ss.ff, d.front().ss.ss.ff, d.front().ss.ss.ss, d.front().ff);
			d.pop_front();
		}
		//cout << cur <<endl;
	}
	
	if(cur == INF) {
		cout<< -1;
		return;
	}
	cout << cur  - 1;
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

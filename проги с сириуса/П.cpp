#include <bits/stdc++.h>
    
using namespace std;
#define int long long
#define f first
#define s second

main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("conveyor.in","r",stdin);
    //freopen("conveyor.out","w",stdout);
    int n;
    cin>>n;
    vector < int > a(n);
    vector < int > b(n);
    vector < int > u(n,0);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	a[i]--;
	}
	for(int i=0;i<n;i++) {
		cin>>b[i];
		b[i]--;
	}

	vector < vector < int> > gg;
	map < int ,int > mp;
	int y =0;
	for(int i=0;i<n;i++) {
		if(u[i]==0) {
			vector < int > jellu;
			int p = i;
			for(;;) {
				jellu.push_back(p);
				u[p] = 1;
				p = a[p];
				if(p==i) {
					break;
				}
			}
			gg.push_back(jellu);
			for(int j=0;j<jellu.size();j++){
				mp[jellu[j]] = y;
			}
			jellu.clear();
			y++;
		}
	}
	vector < int > lol;
	vector < int > lal;
	vector < int > s(n,0);
	for(int i=0;i<n;i++){
		if(s[i]==0) {
			int x = mp[i];
			int k=-1;
			//cout<<b[i]<<endl;
			int h =0;
			for(int j =0; j<gg[x].size(); j++){
			///	cout<<gg[x][j]<<" ";
				if(gg[x][j] == b[i]){
					k = j;
				}
				if(gg[x][j]== i){
					h = j;
				}
			}
			//cout<<endl;
			//cout<<k<<endl;
			if(k==-1){
				cout<<"No";
				return 0;
			}
			//k = k -h;
			if(k == 0){
				k  = gg[x].size();
			}
			lol.push_back(k);
			lal.push_back(gg[x].size());
			s[i] = 1;
			for(int j =0; j<gg[x].size(); j++){
			//	cout<<gg[x][j]<<" "<<" "<<b[gg[x][j]] << " "<<gg[x][(j+k)%(gg[x].size())]<<endl;
				if(b[gg[x][j]] == gg[x][(j+k)%(gg[x].size())]){
					s[gg[x][j]] = 1;
					//break;
				} else {
					cout << "No";
					return 0;
				}
			}
		
		}
	}
	int g =0, kk=-1;
	for(int i=0;i<lol.size();i++){
		if()
	}
	cout<<"Yes";
	return 0;
}

#include <bits/stdc++.h>
    
using namespace std;
#define int long long
#define f first
#define s second
int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}
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
	vector < pair < int ,int > > lol;
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
			if(gg[x].size()!=1) {
			    lol.push_back({k%gg[x].size(),gg[x].size()});
		    }
		//	lal.push_back(gg[x].size());
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
	}//for(int i=0;i<lol.size();i++){
	//	cout<<lol[i].first<<" "<<lol[i].second<<endl;
	//}
	for(int j=0;j<lol.size();j++) {
	int dd= lol[j].first,mo = lol[j].second;
	for(int i=j+1;i<lol.size();i++){
		int fh = gcd(mo, lol[i].second);
		if(lol[i].first%fh != dd%fh){
			cout<<"No";
		    return 0;
		}
	}
}
	/*
	/*
	int md =1;
	int g =0, kk=0;
	for(int i=0;i<lol.size();i++){
		md = md * lal[i];
		lol[i]=lol[i]%lal[i];
		if(g<lal[i]){
			g=lal[i];
			kk=lol[i]%lal[i];
		}
	}
	*/
	/*
	if(lol.size()==1){
		cout<<"Yes";
		return 0;
	}
	sort(lol.begin(),lol.end());
	vector < int > us(n,0);
	for(int i=1;i<lol.size();i++)
	{
		if(lol[i].first==lol[i-1].first){
			if(lol[i].second==lol[i-1].second){
				us[i] = 1;
			}
		}
	}
	int xx=lol[0].second;
	int kkk=0;
	for(int i=0;i<lol.size();i++) {
		if(us[i]==0){
			xx = gcd(xx,lol[i].second);
			kkk++;
		}
	}
	if(kkk==1){
		cout<<"Yes";
		return 0;
	}
	if(xx == 1){
		cout<<"Yes";
		return 0;
	}
	/*
	set < int > st;
	for(int i=0;i<lol.size();i++){
		vector < int > vec;
		for(int ii=0;;ii++){
			int p = ii*lal[i]+lol[i];
		//	cout<<p;
			if(p>md){
				break;
			} 
			if(st.count(p)!=0){
				vec.push_back(p);
				
			}
			if(i==0){
				vec.push_back(p);	
			}
		}
		st.clear();
		for(int i=0;i<vec.size();i++){
			st.insert(vec[i]);
		}
		vec.clear();
	}
	if(st.size()>0){
		cout<<"Yes";
		return 0;
	}
	/*
	for(int i=0;i<lol.size();i++){
		int z = g % lal[i];
		bool f5 =0;
		int  v = kk;
		for(int x=0;x<=lal[i];x++){
			int pp = ((z*x)%lal[i] + v)%lal[i];
			if(pp == lol[i]){
				f5 =1;
				break;
			}
		}
		if(f5==0){
			cout<<"No";
			return 0;
		}
	}
	
	for(int x =0;x<=md;x+=g){
		x+=kk;
		bool f7 = 0;
		for(int i=0;i<lol.size();i++){
			if(x%lal[i]!=lol[i]){
				f7 = 1;
			}
		}
		if(f7 ==0){
			cout<<"Yes";
			return 0;
		}
	}
	*/
	cout<<"Yes";
	return 0;
}

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
    
    int  n = 5;
	vector < int > d(n);
	vector < int > d1(n);
	for(int i1= 1;i1<6;i1++){
	for(int i2= 1;i2<6;i2++){
	for(int i3= 1;i3<6;i3++){
	for(int i4= 1;i4<6;i4++){
	for(int i5= 1;i5<6;i5++){
	for(int i6= 1;i6<6;i6++){
	for(int i7= 1;i7<6;i7++){
	for(int i8= 1;i8<6;i8++){
		for(int i9= 1;i9<6;i9++){
			for(int i10= 1;i10<6;i10++){
	d[0]=i1;
	d[1]=i2;
	d[2]=i3;
	d[3]=i4;
	d[4]=i5;
	d1[0]=i6;
	d1[1]=i7;
	d1[2]=i8;
	d1[3]=i9;
	d1[4]=i10;
	vector < int> o;
	for(int i=0;i<n;i++)
	{
		o.push_back(d[i]);
	}	
	
	sort(o.begin(),o.end());
	bool ff=0;
	for(int i=1;i<n;i++)
	{
		if(o[i]==o[i-1]){
			ff=1;
		}
	}
	if(ff==1){
		continue;
	}
	o.clear();
	for(int i=0;i<n;i++)
	{
		o.push_back(d1[i]);
	}	
	
	sort(o.begin(),o.end());
	 ff=0;
		for(int i=1;i<n;i++)
	{
	if(o[i]==o[i-1]){
		ff=1;
	}
	}
	if(ff==1){
		continue;
	}
	         
	         
	         
	         int ans1=0,ans2=1;
	         
	         
	         		
    vector < int > a(n);
    vector < int > b(n);
    vector < int > c(n);
    for(int i=0;i<n;i++){
    	a[i] = d[i];
    	c[i] = i+1;
	}
	for(int i=0;i<n;i++){
		b[i] = d1[i];
	}
	vector < int> p(n);
	vector < int > g(n,1);
	for(int j=0;j<=100000;j++) {
		bool f =0;
		for(int i=0;i<n;i++){
			p[i]= c[a[i]-1];
		}
		for(int i=0;i<n;i++){
			if(	p[i] != b[i] ){
				f = 1;
			}
		}
	//	cout<<endl;
		if(f==0) {
			ans1 =1;
			
		}
		for(int i=0;i<n;i++){
			c[i] = p[i];
		}
	}

    
	         
	         
	         
	    

    vector < int > u(n,0);
    for(int i=0;i<n;i++){
    	a[i] = d[i];
    	a[i]--;
	}
	for(int i=0;i<n;i++) {
		b[i] = d1[i];
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
				ans2=0;
			}
			//k = k -h;
			if(k == 0){
				k  = gg[x].size();
			}if(gg[x].size()!=1)
			lol.push_back({k%gg[x].size(),gg[x].size()});
		//	lal.push_back(gg[x].size());
			s[i] = 1;
			for(int j =0; j<gg[x].size(); j++){
			//	cout<<gg[x][j]<<" "<<" "<<b[gg[x][j]] << " "<<gg[x][(j+k)%(gg[x].size())]<<endl;
				if(b[gg[x][j]] == gg[x][(j+k)%(gg[x].size())]){
					s[gg[x][j]] = 1;
					//break;
				} else {
					ans2 = 0;
				}
			}
		
		}
	}
	int dd= lol[0].first,mo = lol[0].second;
	for(int i=1;i<lol.size();i++){
		int fh = gcd(mo, lol[i].second);
		if(lol[i].first%fh != dd%fh){
			ans2 =0;
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
	         
	 
	 
	 
	 if(ans2==ans1){
	 	//cout<<"OK"<<endl;
	 }        else {
	 	cout<<"KEK"<<endl;
	 	for(int i=0;i<n;i++){
	 		cout<<d[i]<<" "<<d1[i]<<endl;
		 }
	 	return 0;
	 }
	         
	         
	         
	         
	         
	         
	         
	         
	} 
	} 
	} 
	} 
	} 
	} 
	} 	
	} 
}
}
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
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
	for(int i=0;i<=n;i++){
		for(int  j=0;j<n;j++){
			
		}
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
	cout<<"Yes";
	return 0;
	*/

}

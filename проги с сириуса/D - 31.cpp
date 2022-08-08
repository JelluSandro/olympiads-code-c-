#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, q;
int INF = 1e18;
int const ing = 5e5 + 10;
int tree [4*ing][11];
vector<int> mass;
int zax[11];
void build(int v, int l, int r) {
    if (l == r) {
    	for(int i=0;i<11;i++){
    		if(mass[l]==i) {
        		tree[v][i] = mass[l];
        	//	cout<<tree[v][i]<<" ";
    		} else {
    			tree[v][i] = -1;
			}
		}
    } else {
        build(2 * v, l, (l + r) / 2);
        build(2 * v + 1, (l + r) / 2 + 1, r);
        for(int i=0;i<11;i++){
        	tree[v][i] = max(tree[2 * v][i], tree[2 * v + 1][i]);	
        	//cout<<tree[v][i]<<" ";
		}
    }
}

void rebuildmn(int v, int pos, int l, int r) {
    if (l == r) {
    	for(int i=0;i<11;i++){
    		if(mass[l]==i) {
        		tree[v][i] = mass[l];
    		} else {
    			tree[v][i] = -1;
			}
		}
    } else {
        if (pos <= (l + r) / 2) {
            rebuildmn(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuildmn(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
        for(int i=0;i<11;i++){
        	tree[v][i] = max(tree[2 * v][i], tree[2 * v + 1][i]);	
		}
    }
}

void mx(int v, int tl, int tr, int l, int r) {
    if (l > r) {
		return;
    }
    if (l == tl && r == tr) {
    	for(int i=0;i<11;i++){
    	//	cout<<zax[i]<<" ";
    		zax[i]=max(zax[i],tree[v][i]);
    	//	cout<<zax[i]<<" ";
		}
	//	cout<<endl;
		return;
    }
    int tm = (tl + tr) / 2;
    mx(v * 2, tl, tm, l, min(r, tm));
    mx(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void f1 (){
	for(int j=0;j<q;j++){
		char gg;
		cin>>gg;
		if(gg=='?'){
			int l,r;
			cin>>l>>r;
			vector<int> b;
			for(int i=l-1;i<r;i++){
				b.push_back(mass[i]);
			}
			b.push_back(INF);
			sort(b.begin(),b.end());
			int cnt =0;
			for(int i=0;i<b.size();i++){
				if(b[i]>cnt){
					cout<<cnt<<endl;
					break;
				} else {
					if(b[i]==cnt) {
						cnt++;
					}
				}
			}
		} else {
			int l,r;
			cin>>l>>r;
			mass[l-1]=r;
		}
	}
}
main() {
	cin>> n >> q;
    mass.resize(n+100);
    for(int i=0;i<n;i++){
    	cin>>mass[i];
	}
	if((n<6000)&&(q<6000)){
		f1();
		return 0;
	}
    build(1, 0, n - 1);
    for (int i = 0; i < q; i++) {
    	char ch;
    	cin>>ch;
    	if(ch=='?'){
    		int l ,r;
    		cin>>l>>r;
    		l--;
    		r--;
    		for(int j=0;j<11;j++) {
    			zax[j] = -1;
			}
    		mx(1, 0, n - 1, l, r);
    		int  y = 11;
    		for(int j=0;j<11;j++) {
    			if(zax[j]==-1){
    				y = j;
    				break;
				}
			}
			cout<<y;
			cout<<endl;
		} else {
			int l, r;
			cin>>l>>r;
			l--;
			mass[l] =r;
			rebuildmn(1, l, 0, n - 1);
		}
    }
}

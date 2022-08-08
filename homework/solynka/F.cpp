#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
#define mp make_pair
int const md = 1e6 + 7;
int INF = 1e18;
//vector < pair < int, int > > dp[4 * md];
int n, k, q;
int mass[md];

/*void merge(vector < pair < int ,int > > a,
  vector < pair < int ,int > > b, vector < pair < int ,int > > &c) {
     if(c.size() > 0) {
	    c.clear();
	}
	if(b.size() == 0) {
	    c = a;
	    return;
	    c.push_back(a[0]);
	    for(int i = 1; i < (int)a.size(); ++i) {
		    if(c[(int)c.size() - 1].ss + k >= a[i].ff) {
		    	c[(int)c.size() - 1].ss = max(c[(int)c.size() - 1].ff, a[i].ss);
	    	} else {
	    		c.push_back(a[i]);
	    	}
	    }
	    return;
	} 
	if(a.size() == 0) {
	    c = b;
	    return;
	    c.push_back(b[0]);
	    for(int i = 1; i < (int)b.size(); ++i) {
		    if(c[(int)c.size() - 1].ss + k >= b[i].ff) {
		    	c[(int)c.size() - 1].ss = max(c[(int)c.size() - 1].ff, b[i].ss);
	    	} else {
		    	c.push_back(b[i]);
	    	}
    	}
	    return;
	}
	
	
	
	
	int z = 0;
	
	
	vector < pair < int ,int > > ga;
	
	for(int i = 0; i < (int)a.size(); ++i) {
		for(; z < (int)b.size(); ++z) {
			if(a[i].ff > b[z].ff) {
				ga.push_back(b[z]);
			} else {
				break;
			}
		}
		ga.push_back(a[i]);
	}
	
	
	for(; z < (int)b.size(); ++z) {
		ga.push_back(b[z]);
	} 
	//sort(ga.begin(), ga.end());
  //  c = ga;

	c.push_back(ga[0]);
	for(int i = 1; i < (int)ga.size(); ++i) {
		if(c[(int)c.size() - 1].ss + k >= ga[i].ff) {
			c[(int)c.size() - 1].ss = max(c[(int)c.size() - 1].ff, ga[i].ss);
		} else {
			c.push_back(ga[i]);
		}
	}
	
}
void build(int v, int tl, int tr) {
	if(tl == tr) {
		dp[v].push_back(mp(mass[tl], mass[tl]));
		return;
	}
	if(tl > tr) {
	    return;
	}
	int tm = (tl + tr) / 2;
	build(2 * v, tl, tm);
	build(2 * v + 1, tm + 1, tr);
	merge(dp[2 * v], dp[2 * v + 1], *&dp[v]);
}
vector < pair < int, int > > ans;
void ask (int v, int tl, int tr, int l, int r) {
	if(tl > r || tr < l || tl > tr) {
		return;
	}
	if(tl >= l && tr <= r) {
	    merge(ans, dp[v], *&ans);
		return;
	}
	int tm = (tl + tr) / 2;
	ask(2 * v, tl, tm, l, r);
	ask(2 * v + 1, tm + 1, tr, l, r);
}
*/
void solve() {
    cin >> n >> q >> k;
    for (int i = 0; i < n; ++i) {
        cin >> mass[i];
    }
//	build(1, 0, n - 1);
    for (int ii = 0; ii < q; ++ii) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (k == 0) {
            cout << r - l + 1 << " ";
            continue;
        }
        vector<int> b;
        for (int i = l; i <= r; ++i) {
            b.push_back(mass[i]);
        }
        sort(b.begin(), b.end());
        int tr = -INF, tl = INF;
        int cur = 0;
        for (int i = 0; i < b.size(); ++i) {
            //	cout << b[i] << "\n";
            if (tl - k <= b[i] && tr + k >= b[i]) {
                tl = min(tl, b[i]);
                tr = max(tr, b[i]);
            } else {
                cur++;
                tl = min(tl, b[i]);
                tr = max(tr, b[i]);
            }
        }
        cout << cur << " ";
        // ask(1, 0, n - 1, l, r);
        //	cout << ans.size() << "\n";
        //	ans.clear();
//	}


        //vector < pair < int ,int >  > ga;
        // ga = ans;
        // vector < pair < int ,int > > c;
        //   c.push_back(ga[0]);
        //   for(int i = 1; i < (int)ga.size(); ++i) {
        //	    if(c[(int)c.size() - 1].ss + k >= ga[i].ff) {
        //	    	c[(int)c.size() - 1].ss = max(c[(int)c.size() - 1].ff, ga[i].ss);
        //   	} else {
        //  		c.push_back(ga[i]);
        //   	}
        //   }
        // merge(ga,c,*&c);
        //    cout << ans.size()<<"\n";
        //   ans.clear();
    }

}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

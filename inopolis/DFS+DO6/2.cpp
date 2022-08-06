#include <bits/stdc++.h>

#define int long long
using namespace std;
vector <vector<int>> g;
vector<int> used;
vector<int> vx;
vector<int> vi;
vector<int> pr;
int ott;
int d[(int) 3e5][(int) 50];
int n, s;
int cnt = 0;

void dfs(int v) {
    used[v] = 1;
    vx[v] = cnt;
    cnt++;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == 0) {
            pr[g[v][i]] = v;
            dfs(g[v][i]);
        }
    }
    vi[v] = cnt;
    cnt++;
}

void f(int a1, int a2) {
    //cout<<a1<<"! ";
    ott = a1;
    for (int i = 20; i >= 0; i--) {
        int v = d[a1][i];
        // cout<<vx[v]<<" "<<vx[a2]<<" "<<vi[v]<<" "<<vi[a2]<<endl;
        if ((vx[v] > vx[a2]) || (vi[v] < vi[a2])) {
            a1 = d[a1][i];
            f(a1, a2);
            break;
        }
    }

}

main() {
    cin >> n;
    s = 1;
    s--;
    g.resize(n);
    used.resize(n, 0);
    vx.resize(n);
    vi.resize(n);
    pr.resize(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int a1, a2;
        cin >> a1;
        a1--;
        // a2--;
        g[a1].push_back(i + 1);
        g[i + 1].push_back(a1);
    }
    dfs(s);
    // cout<<"LOL";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 50; j++) {
            d[i][j] = 0;
        }
        // cout<<endl;
    }
    for (int i = 1; i < n; i++) {
        d[i][0] = pr[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < 50; j++) {
            d[i][j] = d[d[i][j - 1]][j - 1];
            //  cout<<d[i][j]<< " ";
        }
        // cout<<endl;
    }
    int k;
    cin >> k;
    for (int ii = 0; ii < k; ii++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        // cout<<vx[a1]<<" "<<vx[a2]<<" "<<vi[a1]<<" "<<vi[a2]<<endl;
        if ((vx[a1] < vx[a2]) && (vi[a1] > vi[a2])) {
            cout << a1 + 1 << endl;
        } else {

            if ((vx[a1] > vx[a2]) && (vi[a1] < vi[a2])) {
                cout << a2 + 1 << endl;
            } else {
                f(a1, a2);
                // cout<<a1<<" ";
                a1 = ott;
                a1 = d[a1][0];
                // cout<<a1<<" ";
                cout << a1 + 1 << endl;
            }
        }
    }
}

#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m, t;
vector<int> k;
vector <vector<int>> a;
int s, w;
queue<int> q1;
queue<int> q2;
vector<int> c;
int cnt = 0;

void bfs(int v) {
    //	cout<<v<<endl;
    c[v] = 2;
    if (v != s) {
        cnt += k[v];
    }
    for (int i = 0; i < a[v].size(); i++) {
        if (c[a[v][i]] == 0) {
            c[a[v][i]] = 1;
            q2.push(a[v][i]);
        }
    }
}

main() {
    cin >> n >> m >> t;
    k.resize(n);
    a.resize(n);
    c.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < m; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        a[a1].push_back(a2);
        a[a2].push_back(a1);
    }
    cin >> s >> w;
    s--;
    cnt = k[s];
    q1.push(s);
    while (q1.size() > 0) {
        while (q1.size() > 0) {
            bfs(q1.front());
            q1.pop();
        }
        //	cout<<cnt<<" "<<w<<endl;
        int g = max(0LL, min(w, min(cnt, t)));
        cnt -= g;
        w -= g;
        if (w > 0) {
            if (cnt == 0) {
                cout << "YES";

                return 0;
            }
        }
        if (w <= 0) {
            cout << "NO";
            return 0;
        }
        if (cnt >= w) {
            cout << "NO";
            return 0;
        }
        while (q2.size() > 0) {
            q1.push(q2.front());
            q2.pop();
        }
    }
//	cout<<w<<" "<<cnt;
    if (w > cnt) {
        cout << "YES";
    } else {
        cout << "NO";
    }


}

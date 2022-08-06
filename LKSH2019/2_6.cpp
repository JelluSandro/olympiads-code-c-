#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second
int Md = 62;

int in(char a) {
    if ('a' <= a && a <= 'z') {
        return (a - 'a');
    }
    if ('A' <= a && a <= 'Z') {
        return (a - 'A' + 26);
    }
    return (a - '0' + 52);
}

char out(int a) {
    if (a < 26) {
        return ('a' + a);
    }
    if (a < 52) {
        return (a - 26 + 'A');
    }
    return (a - 52 + '0');
}

int n;
int const m = 4000;
vector<int> g[m];
int gin[m];
int gout[m];
int used[m];
vector<int> path;

void findpatch(int v) {
    int cnt = g[v].size();
    for (int i = used[v]; i < cnt; ++i) {
        if (i < used[v])
            i = used[v];
        if (i >= cnt)
            break;
        ++used[v];
        findpatch(g[v][i]);
    }
    path.push_back(v);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x1 = in(s[0]) * Md + in(s[1]);
        int x2 = in(s[1]) * Md + in(s[2]);
        g[x1].push_back(x2);
        gin[x1]++;
        gout[x2]++;
    }
    int s = -1;
    for (int i = 0; i < m; i++) {
        if (abs(gin[i] - gout[i]) > 1) {
            cout << "NO\n";
            return;
        }
        if (gin[i] > gout[i]) {
            if (s == -1) {
                s = i;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    if (s == -1) {
        for (int i = 0; i < m; i++) {
            if (gin[i] > 0) {
                s = i;
                break;
            }
        }
    }
    findpatch(s);
    if (path.size() != n + 1) {
        cout << "NO\n";
    } else {
        int vs = s / Md;
        cout << "YES\n";
        cout << out(vs);
        for (int i = 0; i < path.size(); i++) {
            cout << out(path[n - i] % Md);
        }
        cout << "\n";
    }
    return;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

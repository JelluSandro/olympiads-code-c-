#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
vector < pair < int, int > > a;
vector < int > r;
int inf = 1e9 + 7;
void siftup(int v) {
    while (a[v].ff < a[v / 2].ff) {
        swap(r[a[v].ss], r[a[v / 2].ss]);
        swap(a[v], a[v / 2]);
        v = v / 2;
    }
}
void siftdown(int v) {
    while (2 * v < (int)a.size()) {
        int l = 2 * v;
        int rg = 2 * v + 1;
        int j = l;
        if (rg < (int)a.size() && a[rg].ff < a[l].ff) {
            j = rg;
        }
        if (a[v].ff <= a[j].ff) {
            break;
        }
        swap(r[a[v].ss], r[a[j].ss]);
        swap(a[v], a[j]);
        v = j;
    }
}
int main() {
    string s;
    a.push_back({-inf, 0});
    r.push_back(0);
    int o = 0;
    while (cin >> s) {
        o++;
        r.push_back(0);
        if (s == "push") {
            int x;
            cin >> x;
            a.push_back({x, o});
            r[(int)r.size() - 1] = a.size() - 1;
            siftup(a.size() - 1);
        } else if (s == "extract-min") {
            if (a.size() > 1) {
                cout << a[1].ff << " " << a[1].ss << '\n';
                r[a[1].ss] = 0;
                a[1] = a[a.size() - 1];
                r[a[1].ss] = 1;
                a.pop_back();
                if (a.size() > 1) {
                    siftdown(1);
                }
            } else {
                cout << "*\n";
            }
        } else {
            int x, y;
            cin >> x >> y;
            if (r[x] == 0 || a[r[x]].ff < y) {
                continue;
            }
            a[r[x]].ff = y;
            siftup(r[x]);
        }
    }
}
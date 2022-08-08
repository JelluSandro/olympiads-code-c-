#include <iostream>
#include <cstddef>
 
using namespace std;
 
int o[1001];
 
struct St {
    St* l;
    St* r;
    int g;
    St(int _g) {
        g = _g;
        l = NULL;
        r = NULL;
    }
};
 
void add(St *&t, int x, St *&beg) {
    St *tt = new St(x);
    while (1) {
        if(t->g > x) {
            if(t->l != NULL) {
                t = t->l;
                delete[] t->r;
                t->r = NULL;
            } else {
                t = tt;
                beg = t;
                return;
            }
        } else {
            break;
        }
    }
    t->r = tt;
    tt->l = t;
    t = tt;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    int a, b, c;
    cin >> n >> m >> k;
    cin >> a >> b >> c;
    long long ans = 0;
    cin >> o[0];
    St *treap = new St(o[0]);
    St *beg = treap;
    int pr1 = 0, pr2 = o[0], pr3 = 0, pr4 = o[0];
    int j = 0, zn = o[0];
    for(int i = 1; i < n; i++) {
        if(i >= m) {
            ans += beg->g;
        }
        if(i < k) {
            cin >> o[i];
            pr1 = pr2;
            pr2 = o[i];
            add(treap, o[i], beg);
        } else {
            int xx = a * pr1 + b * pr2 + c;
            pr1 = pr2;
            pr2 = xx;
            add(treap, xx, beg);
            }
        if(i >= m) {
            if(j < k) {
                zn = o[j];
                pr3 = pr4;
                pr4 = zn;
            } else {
                int xx = a * pr3 + b * pr4 + c;
                pr3 = pr4;
                pr4 = xx;
                zn = xx;
            }
            j++;
            if(beg->g == zn) {
                beg = beg->r;
                delete[] beg->l;
                beg->l = NULL;
            }
        }
    }
    ans += beg->g;
    cout << ans;
}
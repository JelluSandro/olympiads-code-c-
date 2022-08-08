#include <iostream>
#include <cstddef>
 
using namespace std;
 
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
 
void add(St *&t, int x) {
    St *tt = new St(x);
    tt->l = t;
    t->r = tt;
    t = tt;
}
 
void pop(St *&t) {
    cout << t->g << "\n";
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    St *treap = new St(-1);
    St *beg = treap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char s;
        cin >> s;
        if(s == '+') {
            int x;
            cin >> x;
            add(treap, x);
        } else  {
            beg = beg->r;
            pop(beg);
        }
    }
}
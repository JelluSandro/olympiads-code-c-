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
    t = t->l;
}
 
int ch(St *t) {
    return(t->g);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    St *treap = new St(0);
    string s;
    while (cin >> s) {
        if (s == "+") {
            int x1 = ch(treap);
            pop(treap);
            int x2 = ch(treap);
            pop(treap);
            add(treap, x1 + x2);
        } else if (s == "-") {
            int x1 = ch(treap);
            pop(treap);
            int x2 = ch(treap);
            pop(treap);
            add(treap, x2 - x1);
        } else if (s == "*") {
            int x1 = ch(treap);
            pop(treap);
            int x2 = ch(treap);
            pop(treap);
            add(treap, x1 * x2);
        } else {
            int n = s.size();
            int x = 0;
            for (int i = 0; i < n; i++) {
                x = x * 10 + (s[i] - '0');
            }
            add(treap, x);
        }
    }
    cout << treap->g;
}
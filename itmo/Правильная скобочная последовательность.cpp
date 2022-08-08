#include <iostream>
#include <cstddef>
 
using namespace std;
 
struct St {
    St* l;
    St* r;
    char g;
    St(char _g) {
        g = _g;
        l = NULL;
        r = NULL;
    }
};
 
void add(St *&t, char x) {
    St *tt = new St(x);
    tt->l = t;
    t->r = tt;
    t = tt;
}
 
void pop(St *&t) {
    t = t->l;
}
 
char ch(St *&t) {
    return(t->g);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (cin >> s) {
        St *treap = new St('*');
        int n = s.size();
        bool f = 0;
        for (int  i = 0; i < n; i++) {
            if (s[i] == '[' || s[i] =='(') {
                add(treap, s[i]);
            } else {
                if (s[i] == ')') {
                    if (ch(treap) != '(') {
                        f = 1;
                        cout << "NO\n";
                        break;
                    } else {
                        pop(treap);
                    }
                } else {
                    if (ch(treap) != '[') {
                        f = 1;
                        cout << "NO\n";
                        break;
                    } else {
                        pop(treap);
                    }
                }
            }
        }
        if (f == 0) {
            if (treap->g == '*')
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
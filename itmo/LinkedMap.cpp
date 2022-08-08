#include <vector>
#include <iostream>
 
using namespace std;
const int n = 1046527;
 
long long p = 31;
long long b[30];
 
int hsh(string s) {
    long long cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        cnt = (cnt + (s[i] - 'a') * b[i]) % n;
    }
    return abs((int) cnt);
}
 
struct G {
    G *next;
    G *prev;
    string s;
    string k;
 
    G(G *_prev, string _s, string _k) {
        next = nullptr;
        s = _s;
        prev = _prev;
        k = _k;
    }
};
 
vector<G*> a[n];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    bool flag;
    G *h = nullptr;
    G *next;
    G *prev;
    string y, z;
    b[0] = 1;
    for (i = 1; i < 30; i++) {
        b[i] = b[i - 1] * p;
    }
    string s;
    while (cin >> s) {
        string xx;
        cin >> xx;
        y = xx;
        int x = hsh(xx);
        if (s == "put") {
            cin >> z;
            flag = true;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i]->s == y) {
                    a[x][i]->k = z;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                a[x].push_back(new G(h, y, z));
                if (h != nullptr) {
                    h->next = a[x][(int) a[x].size() - 1];
                }
                h = a[x][(int) a[x].size() - 1];
            }
        } else if (s == "get") {
            flag = true;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i]->s == y) {
                    cout << a[x][i]->k << "\n";
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "none\n";
            }
        } else if (s == "delete") {
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i]->s == y) {
                    next = a[x][i]->next;
                    prev = a[x][i]->prev;
                    if (next != nullptr) {
                        next->prev = prev;
                    }
                    if (prev != nullptr) {
                        prev->next = next;
                    }
                    if (h == a[x][i]) {
                        h = prev;
                    }
                    swap(a[x][i], a[x][(int) a[x].size() - 1]);
                    a[x].pop_back();
                    break;
                }
            }
        } else if (s == "prev") {
            flag = true;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i]->s == y) {
                    if (a[x][i]->prev == nullptr) {
                        cout << "none\n";
                    } else {
                        cout << a[x][i]->prev->k << "\n";
                    }
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "none\n";
            }
        } else {
            flag = true;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i]->s == y) {
                    if (a[x][i]->next == nullptr) {
                        cout << "none\n";
                    } else {
                        cout << a[x][i]->next->k << "\n";
                    }
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "none\n";
            }
        }
    }
}
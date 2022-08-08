#include <vector>
#include <iostream>
 
using namespace std;
const int n = 1046527;
const int m = 101;
 
long long p = 31;
long long b[30];
 
int hsh(string s, int md) {
    long long cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        cnt = (cnt + (s[i] - 'a') * b[i]) % md;
    }
    return abs((int) cnt);
}
 
struct G {
    G *next;
    G *prev;
    string s;
 
    G(G *_prev, string _s) {
        next = nullptr;
        s = _s;
        prev = _prev;
    }
};
 
struct Node {
    string x;
    G *head[m];
    int sz;
 
    Node(string _x, G *h) {
        x = _x;
        for (int i = 0; i < m; i++) {
            head[i] = nullptr;
        }
        head[hsh(h->s, m)] = h;
        sz = 1;
    }
};
 
vector<Node> a[n];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    bool flag;
    bool fl;
    G *h;
    G *next;
    G *prev;
    int j;
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
        int x = hsh(xx, n);
        if (s == "put") {
            cin >> z;
            int zz = hsh(z, m);
            flag = true;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i].x == y) {
                    h = a[x][i].head[zz];
                    flag = false;
                    fl = true;
                    while (h != nullptr) {
                        if (z == h->s) {
                            fl = false;
                            break;
                        }
                        if (h->next == nullptr) {
                            break;
                        }
                        h = h->next;
                    }
                    if (fl) {
                        if (h == nullptr) {
                            a[x][i].head[zz] = new G(h, z);
                        } else {
                            h->next = new G(h, z);
                        }
                        a[x][i].sz++;
                    }
                    break;
                }
            }
            if (flag) {
                a[x].push_back(Node(y, new G(nullptr, z)));
            }
        } else if (s == "get") {
            flag = true;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i].x == y) {
                    flag = false;
                    cout << a[x][i].sz << " ";
                    for (j = 0; j < m; j++) {
                        h = a[x][i].head[j];
                        while (h != nullptr) {
                            cout << h->s << " ";
                            h = h->next;
                        }
                    }
                    cout << "\n";
                }
            }
            if (flag) {
                cout << "0\n";
            }
        } else if (s == "delete") {
            cin >> z;
 
            int zz = hsh(z, m);
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i].x == y) {
                    h = a[x][i].head[zz];
                    fl = false;
                    while (h != nullptr) {
                        if (z == h->s) {
                            fl = true;
                            break;
                        }
                        if (h->next == nullptr) {
                            break;
                        }
                        h = h->next;
                    }
                    if (fl) {
                        next = h->next;
                        prev = h->prev;
                        if (next != nullptr) {
                            next->prev = prev;
                        }
                        if (prev != nullptr) {
                            prev->next = next;
                        } else {
                            a[x][i].head[zz] = next;
                        }
                        a[x][i].sz--;
                    }
                    if (a[x][i].sz == 0) {
                        swap(a[x][i], a[x][(int) a[x].size() - 1]);
                        a[x].pop_back();
                    }
                    break;
                }
            }
 
        } else {
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i].x == y) {
                    swap(a[x][i], a[x][(int) a[x].size() - 1]);
                    a[x].pop_back();
                    break;
                }
            }
        }
    }
}
#include <vector>
#include <iostream>
 
using namespace std;
const int n = 1046527;
 
struct Node {
    string x;
    string y;
 
    Node(string _x, string _y) {
        x = _x;
        y = _y;
    }
};
 
vector<Node> a[n];
long long p = 31;
long long b[30];
 
int hsh(string s) {
    long long cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        cnt = (cnt + (s[i] - 'a') * b[i]) % n;
    }
    return abs((int)cnt);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    bool flag;
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
                if (a[x][i].x == y) {
                    a[x][i].y = z;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                a[x].push_back(Node(y, z));
            }
        } else if (s == "get") {
            flag = false;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i].x == y) {
                    cout << a[x][i].y << "\n";
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << "none\n";
            }
        } else {
            flag = false;
            for (i = 0; i < ((int) a[x].size()); i++) {
                if (a[x][i].x == y) {
                    flag = true;
                    swap(a[x][i], a[x][((int) a[x].size()) - 1]);
                    break;
                }
            }
            if (flag) {
                a[x].pop_back();
            }
        }
    }
}
#include <vector>
#include <iostream>
 
using namespace std;
const int n = 1046527;
vector<int> a[n];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    bool flag;
    int y;
    string s;
    while (cin >> s) {
        int x;
        cin >> x;
        y = x;
        x = abs(x) % n;
        if (s == "insert") {
            flag = true;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i] == y) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                a[x].push_back(y);
            }
        } else if (s == "exists") {
            flag = false;
            for (i = 0; i < (int) a[x].size(); i++) {
                if (a[x][i] == y) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        } else {
            flag = false;
            for (i = 0; i < ((int) a[x].size()); i++) {
                if (a[x][i] == y) {
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
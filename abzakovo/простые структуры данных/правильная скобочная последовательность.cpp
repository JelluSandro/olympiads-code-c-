#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("brackets.in");
    ofstream cout("brackets.out");
    string s;
    while (cin >> s) {
        vector<char> a(s.size());
        int v = 0;
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
            a[v] = s[i];
            v++;
            if (s[i] == ')') {
                if (a[v - 2] == '(') {

                    v = v - 2;
                } else {
                    flag = false;
                    cout << "NO" << "\n";
                    break;

                }
            } else {
                if (s[i] == ']') {

                    if (a[v - 2] == '[') {

                        v = v - 2;
                    } else {
                        flag = false;
                        cout << "NO" << "\n";
                        break;
                    }

                }
            }
        }
        int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                a1++;
            else if (s[i] == ')')
                a2++;
            else if (s[i] == ']')
                a3++;
            else if (s[i] == '[')
                a4++;
        }
        if ((a1 != a2) || (a3 != a4)) {
            if (flag == true)

                cout << "NO" << "\n";
        } else {
            if (flag == true)

                cout << "YES" << "\n";
        }
    }
}

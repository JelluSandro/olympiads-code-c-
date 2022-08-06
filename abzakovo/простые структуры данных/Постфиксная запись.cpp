#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("postfix.in");
    ofstream cout("postfix.out");
    vector<int> a(1000000);
    string b;
    getline(cin, b);
    int c = 0;
    for (int i = 0; i < b.size(); i = i + 2) {

        if (b[i] == '+') {
            int cnt = a[c - 2] + a[c - 1];
            a[c - 2] = cnt;
            c--;

        } else {
            if (b[i] == '-') {
                int cnt = a[c - 2] - a[c - 1];
                a[c - 2] = cnt;
                c--;

            } else {
                if (b[i] == '*') {

                    int cnt = a[c - 2] * a[c - 1];
                    a[c - 2] = cnt;
                    c--;
                } else {

                    a[c] = (int) b[i] - 48;


                    c++;
                }
            }

        }


    }
    cout << a[0];
}

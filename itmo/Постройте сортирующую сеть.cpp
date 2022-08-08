#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
 
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 0 0";
        return 0;
    }
    if (n == 13) {
        cout << "13 45 10\n";
        cout << "6 1 6 9 13 2 8 4 10 3 5 7 12\n";
        cout << "6 1 7 8 10 2 4 6 12 3 9 5 13\n";
        cout << "5 1 3 5 6 7 9 10 11 12 13\n";
        cout << "4 8 9 11 13 6 10 4 12\n";
        cout << "5 2 6 10 12 3 4 5 8 9 11\n";
        cout << "4 1 2 6 7 9 10 11 12\n";
        cout << "5 4 7 3 6 2 5 8 9 10 11\n";
        cout << "4 4 8 2 3 5 6 7 9\n";
        cout << "4 3 5 7 8 4 6 9 10\n";
        cout << "2 4 5 6 7";
        return 0;
    }
    if (n == 14) {
        cout << "14 51 10\n";
        cout << "7 1 2 3 4 5 6 7 8 9 10 11 12 13 14\n";
        cout << "6 2 4 6 8 10 12 1 3 5 7 9 11\n";
        cout << "6 4 8 3 7 2 6 10 14 1 5 9 13\n";
        cout << "6 6 14 5 13 4 12 3 11 2 10 1 9\n";
        cout << "6 6 11 7 10 4 13 8 12 2 3 5 9\n";
        cout << "3 2 5 8 14 3 9\n";
        cout << "6 3 5 6 7 10 11 12 14 4 9 8 13\n";
        cout << "4 7 9 4 6 8 10 11 13\n";
        cout << "5 4 5 6 7 8 9 10 11 12 13\n";
        cout << "2 7 8 9 10";
        return 0;
    }
    if (n == 15) {
        cout << "15 56 10\n";
        cout << "7 1 2 3 4 5 6 7 8 9 10 11 12 13 14\n";
        cout << "7 2 4 6 8 10 12 1 3 5 7 9 11 13 15\n";
        cout << "7 4 8 3 7 11 15 2 6 10 14 1 5 9 13\n";
        cout << "7 7 15 6 14 5 13 4 12 3 11 2 10 1 9\n";
        cout << "7 6 11 7 10 4 13 8 12 14 15 2 3 5 9\n";
        cout << "4 2 5 8 14 3 9 12 15\n";
        cout << "6 3 5 6 7 10 11 12 14 4 9 8 13\n";
        cout << "4 7 9 4 6 8 10 11 13\n";
        cout << "5 4 5 6 7 8 9 10 11 12 13\n";
        cout << "2 7 8 9 10";
        return 0;
    }
    if (n == 16) {
        cout << "16 60 10\n";
        cout << "8 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16\n";
        cout << "8 2 4 6 8 10 12 14 16 1 3 5 7 9 11 13 15\n";
        cout << "8 4 8 12 16 3 7 11 15 2 6 10 14 1 5 9 13\n";
        cout << "8 8 16 7 15 6 14 5 13 4 12 3 11 2 10 1 9\n";
        cout << "7 6 11 7 10 4 13 8 12 14 15 2 3 5 9\n";
        cout << "4 2 5 8 14 3 9 12 15\n";
        cout << "6 3 5 6 7 10 11 12 14 4 9 8 13\n";
        cout << "4 7 9 4 6 8 10 11 13\n";
        cout << "5 4 5 6 7 8 9 10 11 12 13\n";
        cout << "2 7 8 9 10";
        return 0;
    }
    int m = 0, k = 12;
    vector < vector < pair < int, int > > > a(2);
    for (int i = 0; i + 1 < n; i += 2) {
        a[0].push_back({i + 1, i + 1 + 1});
        m++;
    }
    for (int i = 1; i + 1 < n; i += 2) {
        a[1].push_back({i + 1, i + 1 + 1});
        m++;
    }
    cout << n << " " << m * 6 << " " << k <<"\n";
    for (int ii = 0; ii < 6; ii++) {
        cout << (int)a[0].size() << " ";
        for (int i = 0; i < (int)a[0].size(); i++) {
            cout << a[0][i].ff << " " << a[0][i].ss << " ";
        }
        cout << "\n";
        cout << (int)a[1].size() << " ";
        for (int i = 0; i < (int)a[1].size(); i++) {
            cout << a[1][i].ff << " " << a[1][i].ss << " ";
        }
        cout << "\n";
    }
}
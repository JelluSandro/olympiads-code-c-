#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, pair<int, int> > > mass;
vector<pair<int, pair<int, int> > > tree;
vector<int> number;

void push(int v, int x, int y) {
    if (mass[v].second.first >= x) {
        if (tree[mass[v].second.second].first == -1) {
            tree[y].second.first = mass[v].second.second;
            tree[mass[v].second.second].first = y;
        } else {
            push(number[tree[mass[v].second.second].first], x, y);
        }
    } else {
        tree[y].second.first = tree[mass[v].second.second].second.second;
        tree[tree[mass[v].second.second].second.second].first = y;
        tree[y].first = mass[v].second.second;
        tree[mass[v].second.second].second.second = y;
    }
}
main() {
    cin >> n;
    mass.resize(n);
    tree.resize(n);
    number.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> mass[i].first >> mass[i].second.first;
        mass[i].second.second = i;
    }
    sort(mass.begin(), mass.end());
    for (int i = 0; i < n; i++) {
        number[mass[i].second.second] = i;
    }
    for (int i = 0; i < n; i++) {
        tree[i].first = -1;
        tree[i].second.first = -1;
        tree[i].second.second = -1;
    }
    for (int i = 1; i < n; i++) {
        if (mass[i].second.first >= mass[i - 1].second.first) {
            tree[mass[i].second.second].first = mass[i - 1].second.second;
            tree[mass[i - 1].second.second].second.second = mass[i].second.second;
        } else {
            push(i - 1, mass[i].second.first, mass[i].second.second);
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << tree[i].first + 1 << " " << tree[i].second.first + 1
             << " " << tree[i].second.second + 1 << endl;
    }
}

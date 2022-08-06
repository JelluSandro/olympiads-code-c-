#include <bits/stdc++.h>

using namespace std;
int n, a1, b1;
int cur = 0;
bool flag = true;
queue <pair<int, int>> c;

void bfs(pair<int, int> v) {
    if (flag == true) {

        cur++;
        if (v.first == b1) {
            cout << v.second;
            flag = false;

        } else {
            c.push(make_pair((v.first + 1) % n, v.second + 1));
            c.push(make_pair((v.first * 2) % n, v.second + 1));

        }

    }

}


int main() {
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    cin >> n >> a1 >> b1;
    c.push(make_pair(a1, 0));
    while (c.size() != 0) {

        bfs(c.front());
        c.pop();

    }

}

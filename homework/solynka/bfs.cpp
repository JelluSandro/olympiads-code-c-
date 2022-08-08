#include <iostream>
#include <queue>

using namespace std;
int n, k;
queue<int> c;
int const mix = 100;
int a[mix][mix] = {0};
int b[mix] = {false};

void bfs(int v) {
    cout << v << " ";
    b[v] = true;
    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1) {
            if (b[i] == false) {
                c.push(i);
                b[i] = true;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        a[a1][a2] = 1;
        a[a2][a1] = 1;
    }
    b[0] = false;
    c.push(0);
    while (c.size() != 0) {
        bfs(c.front());
        c.pop();
    }

}

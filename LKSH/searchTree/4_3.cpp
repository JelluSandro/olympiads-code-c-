#include <bits/stdc++.h>

#define int long long

using namespace std;
int n = 1e5 + 228;
int INF = 1e9;
vector<int> treemx;
vector<int> mass;

void buildmx(int v, int l, int r) {
    if (l == r) {
        treemx[v] = mass[l];
    } else {
        buildmx(2 * v, l, (l + r) / 2);
        buildmx(2 * v + 1, (l + r) / 2 + 1, r);
        treemx[v] = max(treemx[2 * v], treemx[2 * v + 1]);
    }
}

void rebuildmx(int v, int pos, int l, int r) {
    if (l == r) {
        treemx[v] = mass[l];
    } else {
        if (pos <= (l + r) / 2) {
            rebuildmx(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuildmx(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
        treemx[v] = max(treemx[2 * v], treemx[2 * v + 1]);
    }
}

int mx(int v, int tl, int tr, int l, int r, int cost) {
    if (l > r) {
        return INF;
    }
    if (treemx[v] < cost) {
        return INF;
    }
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    int answer1 = mx(v * 2, tl, tm, l, min(r, tm), cost);
    if (answer1 != INF) {
        return answer1;
    }
    int answer2 = mx(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, cost);
    return answer2;
}

main() {
    int k;
    cin >> n >> k;
    treemx.resize(4 * n);
    mass.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> mass[i];
    }
    buildmx(1, 0, n - 1);
    for (int i = 0; i < k; i++) {
        int input1, input2, input3;
        cin >> input1 >> input2 >> input3;
        if (input1 > 0) {
            input2--;
            int index = mx(1, 0, n - 1, input2, n - 1, input3);
            if (index != INF) {
                cout << index + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
        if (input1 == 0) {
            input2--;
            mass[input2] = input3;
            rebuildmx(1, input2, 0, n - 1);
        }
    }
}

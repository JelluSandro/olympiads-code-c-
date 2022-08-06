#include <bits/stdc++.h>

#define int long long

using namespace std;
int n = 1e5 + 228;
int INF = 1e9;
vector<int> tree;
vector<int> treemx;
vector<long long> mass;

void buildmn(int v, int l, int r) {
    if (l == r) {
        tree[v] = mass[l];
        treemx[v] = mass[l];
    } else {
        buildmn(2 * v, l, (l + r) / 2);
        buildmn(2 * v + 1, (l + r) / 2 + 1, r);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        treemx[v] = max(treemx[2 * v], treemx[2 * v + 1]);
    }
}

void rebuildmn(int v, int pos, int l, int r) {
    if (l == r) {
        tree[v] = mass[l];
        treemx[v] = mass[l];
    } else {
        if (pos <= (l + r) / 2) {
            rebuildmn(2 * v, pos, l, (l + r) / 2);
        } else {
            rebuildmn(2 * v + 1, pos, (l + r) / 2 + 1, r);
        }
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        treemx[v] = max(treemx[2 * v], treemx[2 * v + 1]);
    }
}

int mn(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return INF;
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return min(mn(v * 2, tl, tm, l, min(r, tm)), mn(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int mx(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return -INF;
    }
    if (l == tl && r == tr) {
        return treemx[v];
    }
    int tm = (tl + tr) / 2;
    return max(mx(v * 2, tl, tm, l, min(r, tm)), mx(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

main() {
    tree.resize(4 * n);
    treemx.resize(4 * n);
    mass.resize(n);
    for (int i = 1; i <= n; i++) {
        mass[i - 1] = (i * i) % 12345 + (((i * i) % 23456) * i) % 23456;
    }
    buildmn(1, 0, n - 1);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int input1, input2;
        cin >> input1 >> input2;
        if (input1 > 0) {
            input1--;
            input2--;
            cout << mx(1, 0, n - 1, input1, input2) - mn(1, 0, n - 1, input1, input2) << endl;
        }
        if (input1 < 0) {
            input1 *= -1;
            input1--;
            mass[input1] = input2;
            rebuildmn(1, input1, 0, n - 1);
        }
    }
}

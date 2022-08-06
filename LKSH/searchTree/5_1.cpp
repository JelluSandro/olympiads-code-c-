#include <bits/stdc++.h>

using namespace std;
int n;

struct treap {
    int p, l, r;
};

bool cmp(treap a, treap b) {
    return a.p < b.p;
}

vector <treap> mass;
vector <treap> tree;
vector<int> number;

void push(int v, int x, int y) {
    if (mass[v].l >= x) {
        if (tree[mass[v].r].p == -1) {
            tree[y].l = mass[v].r;
            tree[mass[v].r].p = y;
        } else {
            push(number[tree[mass[v].r].p], x, y);
        }
    } else {
        tree[y].l = tree[mass[v].r].r;
        tree[tree[mass[v].r].r].p. = -0[p
                p[][]
        [p['p[['p] = y;
        tree[y].p = mass[v].r;
        tree[mass[v].r].r = y;
    }
}

main() {
    cin >> n;
    mass.resize(n);
    tree.resize(n);
    number.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> mass[i].p >> mass[i].l;
        mass[i].r = i;
    }
    sort(mass.begin(), mass.end(), cmp);
    for (int i = 0; i < n; i++) {
        number[mass[i].r] = i;
    }
    for (int i = 0; i < n; i++) {
        tree[i].p = -1;
        tree[i].l = -1;
        tree[i].r = -1;
    }
    for (int i = 1; i < n; i++) {
        if (mass[i].l >= mass[i - 1].l) {
            tree[mass[i].r].p = mass[i - 1].r;
            tree[mass[i - 1].r].r = mass[i].r;
        } else {
            push(i - 1, mass[i].l, mass[i].r);
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << tree[i].p + 1 << " " << tree[i].l + 1 << " " << tree[i].r + 1 << endl;
    }
}

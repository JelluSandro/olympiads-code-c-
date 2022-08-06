#include <bits/stdc++.h>

using namespace std;
long long y = -1;
long long mod = 1e9;

struct Node {
    int x;
    int y;
    int sz;
    long long sm;
    Node *l, *r;

    Node(int _x) {
        x = _x;
        y = rand();
        sz = 1;
        sm = 0;
        l = r = nullptr;
    }
};

int get_sz(Node *t);

void update(Node *t);

Node *merge(Node *t1, Node *t2) {
    if (t1 == nullptr) { return t2; }
    if (t2 == nullptr) { return t1; }
    if (t1->y > t2->y) {
        t1->r = merge(t1->r, t2);
        update(t1);
        return t1;
    } else {
        t2->l = merge(t1, t2->l);
        update(t2);
        return t2;
    }
}

void split(Node *t, int x, Node *&t1, Node *&t2) {
    if (t == nullptr) {
        t1 = t2 = nullptr;
        return;
    }
    if (t->x < x) {
        split(t->r, x, t->r, t2);
        t1 = t;
    } else {
        split(t->l, x, t1, t->l);
        t2 = t;
    }
    update(t);
}

int get_sz(Node *t) {
    if (t == nullptr) { return 0; }
    return t->sz;
}

long long get_sm(Node *t) {
    if (t == nullptr) { return 0; }
    return t->sm;
}

void update(Node *t) {
    if (t != nullptr) {
        t->sz = 1 + get_sz(t->l) + get_sz(t->r);
        t->sm = t->x + get_sm(t->l) + get_sm(t->r);
    }
}

void add(Node *&t, int x) {
    Node *t1, *t2;
    split(t, x, t1, t2);
    Node *new_tree = new Node(x);
    t = merge(merge(t1, new_tree), t2);
}

long long sum(Node *&t, int l, int r) {
    Node *t1, *t2, *t3, *t4;
    split(t, l, t1, t2);
    split(t2, r + 1, t3, t4);
    long long ans = get_sm(t3);
    t = merge(t1, merge(t3, t4));
    return (ans);
}

int main() {
    int input;
    cin >> input;
    char s;
    Node *treap = nullptr;
    map<int, int> mp;
    while (cin >> s) {
        if (s == '+') {
            int x;
            cin >> x;
            if (y != -1) {
                x = ((long long) x + y) % mod;
                y = -1;
            }
            if (mp[x] == 0) {
                mp[x] = 1;
                add(treap, x);
            }
        }
        if (s == '?') {
            int l, r;
            cin >> l >> r;
            y = sum(treap, l, r);
            cout << y << "\n";
        }
    }
}

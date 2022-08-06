#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    int y;
    int sz;
    Node *l, *r;

    Node(int _x) {
        x = _x;
        y = rand();
        sz = 1;
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

void update(Node *t) {
    if (t != nullptr) {
        t->sz = 1 + get_sz(t->l) + get_sz(t->r);
    }
}

void add(Node *&t, int x) {
    Node *t1, *t2;
    split(t, x, t1, t2);
    Node *new_tree = new Node(x);
    t = merge(merge(t1, new_tree), t2);
}

void remove(Node *&t, int x) {
    Node *t1, *t2, *t3, *t4;
    split(t, x, t1, t2);
    split(t2, x + 1, t3, t4);
    t = merge(t1, t4);
    delete t3;
}

void print(Node *t) {
    if (t != nullptr) {
        print(t->l);
        cout << t->x << " ";
        print(t->r);
    }
}

int get_k(Node *t, int k) {
    if (k < get_sz(t->l)) {
        return get_k(t->l, k);
    } else if (k == get_sz(t->l)) {
        return t->x;
    } else {
        return get_k(t->r, k - get_sz(t->l) - 1);
    }
}

void ans2(Node *&t) {
    if (t == nullptr) {
        cout << "none\n";
    } else {
        if (t->l == nullptr) {
            cout << t->x << endl;
        } else {
            ans2(t->l);
        }
    }
}

void next(Node *&t, int x) {
    Node *t1, *t2;
    split(t, x + 1, t1, t2);
    ans2(t2);
    t = merge(t1, t2);
}

void ans1(Node *&t) {
    if (t == nullptr) {
        cout << "none\n";
    } else {
        if (t->r == nullptr) {
            cout << t->x << endl;
        } else {
            ans1(t->r);
        }
    }
}

void prev(Node *&t, int x) {
    Node *t1, *t2;
    split(t, x, t1, t2);
    ans1(t1);
    t = merge(t1, t2);
}

int main() {
    int input;
    cin >> input;
    string s;
    Node *treap = nullptr;
    map<int, int> mp;
    while (cin >> s) {
        int x;
        cin >> x;
        if (s == "+1") {
            add(treap, x);
        }
        if (s == "1") {
            add(treap, x);
        }
        if (s == "-1") {
            remove(treap, x);
        }
        if (s == "0") {
            cout << get_k(treap, treap->sz - x) << endl;
        }
    }
}

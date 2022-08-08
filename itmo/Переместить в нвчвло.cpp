#include <bits/stdc++.h>
 
using namespace std;
 
struct Node {
    int y;
    int sz;
    int val;
    Node *l, *r;
};
 
Node *new_node(int val) {
    Node *result = new Node;
    result->y = rand();
    result->sz = 1;
    result->val = val;
    result->l = result->r = nullptr;
    return result;
}
 
int get_sz(Node *t) {
    if (t == nullptr) {
        return 0;
    }
    return t->sz;
}
 
void upd_sz(Node *t) {
    if (t == nullptr) {
        return;
    }
    t->sz = 1 + get_sz(t->l) + get_sz(t->r);
}
 
Node *merge(Node *t1, Node *t2) {
    if (t1 == nullptr) {
        return t2;
    }
    if (t2 == nullptr) {
        return t1;
    }
    if (t1->y > t2->y) {
        t1->r = merge(t1->r, t2);
        upd_sz(t1);
        return t1;
    } else {
        t2->l = merge(t1, t2->l);
        upd_sz(t2);
        return t2;
    }
}
 
void split(Node *t, int x, Node *&t1, Node *&t2) {
    if (t == nullptr) {
        t1 = t2 = nullptr;
        return;
    }
    if (get_sz(t->l) < x) {
        split(t->r, x - get_sz(t->l) - 1, t->r, t2);
        t1 = t;
    } else {
        split(t->l, x, t1, t->l);
        t2 = t;
    }
    upd_sz(t);
}
 
Node *from_vector(const vector<int> &v) {
    Node *result = nullptr;
    for (int i = 0; i < (int)v.size(); ++i) {
        result = merge(result, new_node(v[i]));
    }
    return result;
}
 
int get_value(Node *t, int pos) {
    int my_idx = get_sz(t->l);
    if (pos < my_idx) {
        return get_value(t->l, pos);
    } else if (pos == my_idx) {
        return t->val;
    } else {
        return get_value(t->r, pos - my_idx - 1);
    }
}
 
Node *to_front(Node *t, int l1, int r1) {
    Node *t1, *t2, *t3, *t4;
    split(t, r1 + 1, t1, t2);
    split(t1, l1, t3, t4);
    return merge(t4, merge(t3, t2));
}
 
void print_tree(Node *t) {
    if (t == nullptr) { return; }
    print_tree(t->l);
    cout << t->val << " ";
    print_tree(t->r);
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        numbers[i] = i + 1;
    }
    Node *tree = from_vector(numbers);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        tree = to_front(tree, l - 1, r - 1);
    }
    print_tree(tree);
    return 0;
}
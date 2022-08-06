#include <bits/stdc++.h>

using namespace std;
vector<int> parent;
vector<int> rnk;
vector<int> answer;
int n;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int lista, int listb) {
    lista = find_set(lista);
    listb = find_set(listb);
    if (lista != listb) {
        if (rnk[lista] < rnk[listb])
            swap(lista, listb);
        parent[listb] = lista;
        if (rnk[lista] == rnk[listb])
            ++rnk[lista];
    }
}

int main() {
    cin >> n;
    parent.resize(n, 0);
    rnk.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
    int m;
    cin >> m;
    int k;
    cin >> k;
    for (int i = 0; i < m; i++) {
        int not_use1, not_use2;
        cin >> not_use1 >> not_use2;
    }
    vector < pair < string, pair < int, int > > > input_data;
    for (int i = 0; i < k; i++) {
        pair <string, pair<int, int>> qustion;
        cin >> qustion.first >> qustion.second.first >> qustion.second.second;
        input_data.push_back(qustion);
    }
    for (int i = k - 1; i >= 0; i--) {
        if (input_data[i].first == "ask") {
            int pr1 = find_set(input_data[i].second.first - 1);
            int pr2 = find_set(input_data[i].second.second - 1);
            if (pr1 == pr2) {
                answer.push_back(1);
            } else {
                answer.push_back(0);
            }
        } else {
            union_sets(input_data[i].second.first - 1, input_data[i].second.second - 1);
        }
    }
    if ((int) answer.size() > 0)
        for (int i = (int) answer.size() - 1; i >= 0; i--) {
            if (answer[i] == 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
}

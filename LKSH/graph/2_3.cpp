#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, kk;
    long long INF = 4e18;
    cin >> n >> m >> kk;
    long long d[n][n];
    int p[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = INF;
            p[i][j] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        long long v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        v1--;
        v2--;
        d[v1][v2] = cost;
    }
    vector<int> ot(kk);
    for (int i = 0; i < kk; i++) {
        cin >> ot[i];
        ot[i]--;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (d[j][k] < d[j][i] + d[i][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                    p[j][k] = p[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> answer;
    for (int i = 0; i < kk - 1; i++) {
        int f = ot[i];
        while (f != ot[i + 1]) {
            cout << f << " ";
            answer.push_back(f);
            f = p[f][ot[i + 1]];
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] + 1 << " ";
    }
}

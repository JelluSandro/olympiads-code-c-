#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second
#define forin for(int i =0;i<n;i++)
#define forout for(int i =n -1;i>=0;i--)
#define intn int n; cin>>n;
#define ld long double
long long INF = 1e18 + 7;
long double EPS = 0.000001;
//set<int>::iterator it = st.begin();it!=st.end();it++
//cout<<fixed<<setprecision(10)<<l;
int gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return (a);
}

bool cmp(int a, int b) {
    if (a < b) {
        return 1;
    } else {
        return 0;
    }
}

int n, k;

void f(vector<int> a, int m, int mx) {
    if (m == n) {
        forin {
            cout << a[i] << " ";
        }
        cout << "\n";
    } else {
        for (int i = n - m; i <= mx; i++) {
            a[m] = i;
            f(a, m + 1, i - 1);
        }
    }
}

main() {
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    vector<int> a(n, 0);
    f(a, 0, k);
}

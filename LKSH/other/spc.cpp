#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second
#define forin for(int i =0;i<n;i++)
#define forout for(int i =n -1;i>=0;i--)
#define intn int n; cin>>n;
//set<int>::iterator it = st.begin();it!=st.end();it++
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

main() {

}

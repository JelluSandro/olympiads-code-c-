#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long


main() {
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int b[n][m];
	for(int i =0;i < n;i++) {
		for(int j =0;j<m;j++) {
			cin >> b[i][j];
		}
	}
	int d[n][m];
	for(int i=0;i < n;i++) {
		for(int j= 0;j < m;j++) {
			cin >> d[i][j];
		}
	}
	int a[n][m];
	int aa[n][m];
	memset(a, -1, sizeof(a));
	memset(aa, -1, sizeof(aa));
	a[0][0] = b[0][0];
	aa[n - 1][m - 1] = d[n - 1][m - 1];
//	cout << d[n - 1][m - 1]<<endl;;
	for(int i =0;i < n;i++) {
		for(int j =0;j< m;j++) {
			int c = 1;
			if(j!=0) {
				c &= b[i][j - 1];
			}
			if(i!=0) {
				c &= b[i - 1][j];
			}
			if(c == 0 && b[i][j] == 1) {
				cout << -1;
				return 0;
			}
			if(c == 0 && b[i][j] == 0) {
				a[i][j] = -1;
			}
			if(c == 1 && b[i][j] == 1) {
				a[i][j] = 1;
			}
			if(c == 1 && b[i][j] == 0) {
				a[i][j] = 0;
			}
		}
	}
	for(int i = n - 1; i >= 0;i--) {
		for(int j = m - 1;j>=0 ;j--) {
			int c = 1;
			if(j + 1 != m) {
				c &= d[i][j + 1];
			}
			if(i + 1 != n) {
				c &= d[i + 1][j];
			}
			if(c == 0 && d[i][j] == 1) {
				cout << -1;
				return 0;
			}
			if(c == 0 && d[i][j] == 0) {
				aa[i][j] = -1;
			}
			if(c == 1 && d[i][j] == 1) {
				aa[i][j] = 1;
			}
			if(c == 1 && d[i][j] == 0) {
				aa[i][j] = 0;
			}
		}
	}
	for(int i =0;i < n;i++) {
		for(int j =0;j < m;j++) {
			if(a[i][j] != -1 && aa[i][j] != -1 && a[i][j] != aa[i][j]) {
				cout << -1;
				return 0;
			} else {
				if(a[i][j] == -1) {
					a[i][j] = aa[i][j];
				}
				if(a[i][j] == -1) {
					a[i][j] = 1;
				}
			} 
		}
	}
	for(int i =0;i < n;i++) {
		for(int j =0;j < m;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

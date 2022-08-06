#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    long double h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    long double hmax[1001][6];
    long double hmin[1001][6];
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 6; j++) {
            hmax[i][j] = 0;
            hmin[i][j] = 0;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int k = max(h[i], h[i + 1]);
        int kk = min(h[i], h[i + 1]);
        //	cout<<kk<<endl;
        hmax[k][0] += h[i] / 2 + h[i + 1] / 2;
        hmax[k][4] += 1;
        if (max(h[i], h[i + 1]) - min(h[i], h[i + 1]) != 0) {
            hmax[k][1] += (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
            hmax[k][2] += (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
            hmax[k][3] += (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                          / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
            hmin[kk][1] += (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
            hmin[kk][2] += (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
            hmin[kk][3] += (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                           / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
        }
        //	cout<<k<<" "<<(1/(max(h[i],h[i+1]) - min(h[i],h[i+1])))/2<<" "<<
        //	(min(h[i],h[i+1])/(max(h[i],h[i+1]) - min(h[i],h[i+1])))<<" "<<
        //	(min(h[i],h[i+1])*(min(h[i],h[i+1])))
        //	/(max(h[i],h[i+1]) - min(h[i],h[i+1]))<<endl;
    }
    for (int ii = 0; ii < q; ii++) {
        char c;
        cin >> c;
        if (c == 'Q') {
            int x;
            cin >> x;
            long double x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
            for (int i = 0; i < 1001; i++) {
                if (i <= x) {
                    //	if(hmax[i][0]!=0){
                    //	cout<<hmax[i][1]<<" "<<i<<endl;
                    //	}
                    x1 += hmax[i][0];
                    x2 += hmax[i][4];
                    x3 -= hmax[i][1];
                    x4 -= hmax[i][2];
                    x5 -= hmax[i][3];
                } else {
                    //	if(hmax[i][1]!=0)
                    //cout<<hmax[i][1]<<":"<<i<<endl;

                }
            }
            for (int i = 0; i < 1001; i++) {
                if (i < x) {
                    //	if(hmin[i][1]!=0)
                    //	cout<<hmin[i][1]<<" "<<i<<" "<<x<<endl;
                    x3 += hmin[i][1];
                    x4 += hmin[i][2];
                    x5 += hmin[i][3];
                }
            }
            //	cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<x5<<" "<<endl;
            long double s = x * x2 - x1 + x * x * x3 - x * x4 + x5 / 2;
            //	cout<<x*x*x3<<" "<<x*x4<<" "<<x5<<endl;
            //	cout<<x*x2 - x1<<endl;
            cout << fixed;
            cout << setprecision(10) << s << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            if (x != 0) {
                int i = x - 1;
                int k = max(h[i], h[i + 1]);
                int kk = min(h[i], h[i + 1]);
                hmax[k][0] -= (h[i] / 2 + h[i + 1] / 2);
                hmax[k][4] -= 1;
                if (max(h[i], h[i + 1]) - min(h[i], h[i + 1]) != 0) {
                    hmax[k][1] -= (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
                    hmax[k][2] -= (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
                    hmax[k][3] -= (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                                  / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
                    hmin[kk][1] -= (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
                    hmin[kk][2] -= (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
                    hmin[kk][3] -= (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                                   / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
                }
            }
            if (x + 1 < n) {
                int i = x;
                int k = max(h[i], h[i + 1]);
                int kk = min(h[i], h[i + 1]);
                hmax[k][0] -= (h[i] / 2 + h[i + 1] / 2);
                hmax[k][4] -= 1;
                if (max(h[i], h[i + 1]) - min(h[i], h[i + 1]) != 0) {
                    hmax[k][1] -= (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
                    hmax[k][2] -= (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
                    hmax[k][3] -= (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                                  / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
                    hmin[kk][1] -= (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
                    hmin[kk][2] -= (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
                    hmin[kk][3] -= (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                                   / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
                }
            }
            h[x] = y;
            if (x != 0) {
                int i = x - 1;
                int k = max(h[i], h[i + 1]);
                int kk = min(h[i], h[i + 1]);
                hmax[k][0] += h[i] / 2 + h[i + 1] / 2;
                hmax[k][4] += 1;
                if (max(h[i], h[i + 1]) - min(h[i], h[i + 1]) != 0) {
                    hmax[k][1] += (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
                    hmax[k][2] += (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
                    hmax[k][3] += (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                                  / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
                    hmin[kk][1] += (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
                    hmin[kk][2] += (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
                    hmin[kk][3] += (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                                   / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
                }
            }
            if (x + 1 < n) {
                int i = x;
                int k = max(h[i], h[i + 1]);
                int kk = min(h[i], h[i + 1]);
                hmax[k][0] += h[i] / 2 + h[i + 1] / 2;
                hmax[k][4] += 1;
                if (max(h[i], h[i + 1]) - min(h[i], h[i + 1]) != 0) {
                    hmax[k][1] += (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
                    hmax[k][2] += (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
                    hmax[k][3] += (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                                  / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
                    hmin[kk][1] += (1 / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]))) / 2;
                    hmin[kk][2] += (min(h[i], h[i + 1]) / (max(h[i], h[i + 1]) - min(h[i], h[i + 1])));
                    hmin[kk][3] += (min(h[i], h[i + 1]) * (min(h[i], h[i + 1])))
                                   / (max(h[i], h[i + 1]) - min(h[i], h[i + 1]));
                }
            }
        }
    }
}

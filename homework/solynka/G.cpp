#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ff first
#define ss second
#define mp make_pair

int const md = 2010;
int a[md][md];

main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (n % 2 == 1) {

        memset(a, 0, sizeof(a));

        for (int i = 0; i < n; i++) {
            string t;
            cin >> t;
            reverse(t.begin(), t.end());
            for (int j = 0; j < t.size(); j++) {
                a[i][j] = t[j] - '0';
            }
        }

        int b[md];
        memset(b, 0, sizeof(b));

        string t;
        cin >> t;
        reverse(t.begin(), t.end());

        for (int i = 0; i < t.size(); i++) {
            b[i] = t[i] - '0';
        }

        string x = "";

        vector<int> cnt(n, 0);

        vector<int> pr(n, 0);

        if (n % 2 == 1) {


            for (int i = 0; i < md; ++i) {
                int cur = 0;
                for (int j = 0; j < n; j++) {
                    int zn = 0;
                    int p = 0;
                    zn = a[j][i];
                    zn += cnt[j];
                    p = zn / 2;
                    cnt[j] = p;
                    zn %= 2;
                    a[j][i] = zn;
                    if (zn == 1) {
                        cur++;
                    }
                }
                int c = b[i];
                if (cur % 2 == c) {
                    x += '0';
                } else {
                    x += '1';
                    for (int j = 0; j < n; j++) {
                        int zn = 0;
                        int p = 0;
                        zn = a[j][i];
                        zn += 1;
                        p = zn / 2;
                        cnt[j] += p;
                        zn = zn % 2;
                        a[j][i] = zn;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (cnt[i] == 1) {
                    cout << -1;
                    return 0;
                }
            }
        }
        reverse(x.begin(), x.end());
        bool ff = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '1') {
                ff = 1;
                cout << 1;
            } else {
                if (ff == 1) {
                    cout << 0;
                }
            }
        }
        if (ff == 0) {
            cout << 0;
        }
    } else {




        /*

        string cf = "";
        vector < int > aa(n);
        for(int i = 0;i < n;i++) {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            int x = 0;
            int k = 1;
            for(int j = 0;j < s.size();j++) {
                x = x + (s[j] - '0') * k;
                k*=2;
            }
            aa[i] = x;
        }
        string t;
        cin >> t;
        reverse(t.begin(), t.end());
        int bb = 0;
        int k = 1;
        for(int j = 0;j < t.size();j++) {
            bb = bb + (t[j] - '0') * k;
            k*=2;
        }
        bool fl = 0;
        for(int i =0; i < 1e6;i++) {
            int o = 0;
            for(int j = 0 ; j< n;j++) {
                o ^= (aa[j] + i);
            }
            if(o == bb) {
                int k = (1 << 20);
                bool ff = 0;
                while(k > 0) {
                    int zn = i /k;
                    i %= k;
                    k /= 2;
                    if(zn == 1) {
                        ff =1;
                        cout << 1;
                    } else {
                        if(ff == 1) {
                            cout << 0;
                        }
                    }
                }
                if(ff == 0) {
                    cout << ff;
                }
                fl = 1;
                break;
                //return  0;
            }
        }
        if(fl == 0) {
            cout << -1;
            return 0;
        }


        */
        int mm = 0;
        for (int i = 0; i < n; ++i) {
            string t;
            cin >> t;
            mm = max(mm, (long long) t.size() + 1);
            reverse(t.begin(), t.end());
            for (int j = 0; j < t.size(); ++j) {
                a[i][j] = (t[j] - '0');
            }
        }
        string t;
        cin >> t;
        mm = max(mm, (long long) t.size() + 1);
        int hh[md];
        memset(hh, 0, sizeof(hh));
        reverse(t.begin(), t.end());
        for (int j = 0; j < t.size(); ++j) {
            hh[j] = (t[j] - '0');
        }
        vector<int> pol(n, 0);
        deque < pair < string, vector < int > > > d;
        deque < pair < string, vector < int > > > dd;
        d.push_back(mp("", pol));
        for (int ii = 0; ii < mm; ++ii) {
            int y = d.size();
            for (; y > 0; y--) {
                string s1 = d.front().ff;
                vector<int> s2 = d.front().ss;
                d.pop_front();
                vector<int> s3(n, 0);
                int cc = 0;
                for (int i = 0; i < n; ++i) {
                    s2[i] += a[i][ii];
                    cc += s2[i] % 2;
                }
                if (cc % 2 == hh[ii]) {
                    for (int i = 0; i < n; ++i) {
                        s3[i] = s2[i] / 2;
                    }
                    d.push_back(mp(s1 + '0', s3));
                    for (int i = 0; i < n; ++i) {
                        s3[i] = (s2[i] + 1) / 2;
                    }
                    d.push_back(mp(s1 + '1', s3));
                }
            }
        }
        if (d.size() == 0) {
            cout << -1;
        } else {
            string oo = d.front().ff;
            reverse(oo.begin(), oo.end());
            int ll = 0;
            for (int i = 0; i < (int) oo.size(); ++i) {
                if (oo[i] == '0' && ll != 0) {
                    cout << 0;
                }
                if (oo[i] == '1') {
                    cout << 1;
                    ll = 1;
                }
            }
        }

        return 0;


        /*

        memset(a, 0, sizeof(a));

        for(int i = 0; i < n; i++) {
            string t;
            cin >> t;
          // t = pl[i];
            reverse(t.begin(), t.end());
            for(int j = 0; j < t.size(); j++) {
                a[i][j] = t[j] - '0';
            }
        }

        int b[md];
        memset(b, 0, sizeof(b));

        string t;
        cin >> t;
        reverse(t.begin(), t.end());

        for(int i = 0; i < t.size(); i++) {
            b[i] = t[i] - '0';
        }

        int ev[n];
        vector < int > x(md, 0);

        vector < int > cnt(n, 0);

        vector < int > pr(n, 0);

        for(int i = 0; i < md; i++) {
            int cur = 0;
            for(int j = 0;j < n;j++) {
                int zn = a[j][i];
                zn += cnt[j];
                cnt[j] = zn/2;
                zn %= 2;
                a[j][i] = zn;
                if(zn == 1) {
                    cur++;
                }
            }
            if(cur % 2 == b[i]) {

            } else {

                if(i == 0) {
                    cout << -1;
                    return 0;
                }



                /*
                x[i - 1] = 1;
                for(int j =0;j < n;j++) {
                    int zn = a[j][i - 1];
                    zn += 1;
                    pr[j] = zn / 2;
                }
                int cc = 0;
                for(int j =0;j < n;j++) {
                    int zn = a[j][i];
                    zn += pr[j];
                    cnt[j]+= zn/2;
                    a[j][i] = zn % 2;
                    if(zn % 2 == 1) {
                        cc++;
                    }
                }
                if(cc % 2 != c) {
                    cout << -1;
                    return 0;
                }



                bool pol = 0;
                for(int q = i - 1; q >= 0; q--) {
                    if(x[q] == 1) {
                        break;
                    }
                    memset(ev, 1, sizeof(ev));
                    int ac = 0;
                    bool pid = 0;
                    for(int w = q; w <= i; w++) {
                        ac = 0;
                        for(int j = 0; j < n; j++) {
                            int zn = a[j][w];
                            zn += ev[j];
                            ev[j] = zn / 2;
                            if(zn % 2 == 1) {
                                ac++;
                            }
                        }
                        if(ac % 2 != b[w]) {
                            pid = 1;
                            break;
                        }
                    }
                    memset(ev, 1, sizeof(ev));
                    if(pid == 0) {
                        x[q] = 1;
                        for(int w = q; w <= i; w++) {
                            for(int j = 0; j < n; j++) {
                                int zn = a[j][w];
                                zn += ev[j];
                                ev[j] = zn / 2;
                                a[j][w] = zn % 2;
                            }
                        }
                        for(int j = 0; j < n; j++) {
                            cnt[j] += ev[j];
                        }
                        pol = 1;
                       // break;
                       break;
                    }
                }
                if(pol == 0) {
                    cout << -1;
                    return 0;
                }









            }
        }



        bool ff = 0;
        for(int i = md -1; i >= 0; i--) {
            if(x[i] == 1) {
                ff = 1;
                cout << 1;
            } else {
                if(ff == 1){
                    cout << 0;
                }
            }
        }
        if(ff == 0 ) {
            cout<<0;
        }
        */

    }
}


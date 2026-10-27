#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m=1e9+7;
struct matran {
    ll x[5][5];
    friend matran operator*(matran a, matran b) {
        matran c;
        for (ll i = 0; i < 5; i++) {
            for (ll j = 0; j < 5; j++) {
                c.x[i][j] = 0;
                for (ll k = 0; k < 5; k++) {
                    c.x[i][j] += a.x[i][k] * b.x[k][j];
                    c.x[i][j] %= m;
                }
            }
        }
        return c;
    }
};

matran bp(matran a, ll n) {
    if (n == 1) {
        return a;
    }
    matran tmp = bp(a, n / 2);
    tmp = tmp * tmp;
    if (n % 2 == 1) {
        tmp=tmp*a;
    }
    return tmp;
}
ll dp[1000005];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
//    n-=2;
    matran a;
    a.x[0][0] = 0;
    a.x[0][1] = 1;
    a.x[0][2] = 1;
    a.x[0][3] = 1;
    a.x[0][4] = 1;
    a.x[1][0] = 1;
    a.x[1][1] = 0;
    a.x[1][2] = 1;
    a.x[1][3] = 0;
    a.x[1][4] = 1;
	a.x[2][0] = 1;
    a.x[2][1] = 1;
    a.x[2][2] = 0;
    a.x[2][3] = 1;
    a.x[2][4] = 0;
    a.x[3][0] = 1;
    a.x[3][1] = 0;
    a.x[3][2] = 1;
    a.x[3][3] = 0;
    a.x[3][4] = 1;
    a.x[4][0] = 1;
    a.x[4][1] = 1;
    a.x[4][2] = 0;
    a.x[4][3] = 1;
    a.x[4][4] = 0;
   	
    matran res = bp(a,n);
    cout << res.x[0][0];

    return 0;
}
 

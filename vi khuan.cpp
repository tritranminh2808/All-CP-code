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
    ll X,Y; cin >> X >> Y;
    cin >> n;
	if(n==0){
		cout << X%m; return 0;
	}
	if(n==1){
		cout << Y%m; return 0;
	}
//    n-=2;
    matran a;
    a.x[0][0] = 1;
    a.x[0][1] = 2;
    a.x[0][2] = 3;
    a.x[0][3] = 6;
    a.x[0][4] = 3;
    a.x[1][0] = 1;
    a.x[1][1] = 0;
    a.x[1][2] = 0;
    a.x[1][3] = 0;
    a.x[1][4] = 0;
	a.x[2][0] = 0;
    a.x[2][1] = 0;
    a.x[2][2] = 1;
    a.x[2][3] = 2;
    a.x[2][4] = 1;
    a.x[3][0] = 0;
    a.x[3][1] = 0;
    a.x[3][2] = 0;
    a.x[3][3] = 1;
    a.x[3][4] = 1;
    a.x[4][0] = 0;
    a.x[4][1] = 0;
    a.x[4][2] = 0;
    a.x[4][3] = 0;
    a.x[4][4] = 1;
   	vector <ll> base;
   	base.push_back(Y%m);
   	base.push_back(X%m);
   	base.push_back(1);
   	base.push_back(1);
   	base.push_back(1);
    matran res = bp(a,n-1);
//	matran sol=res*base;
	ll sol=0;
	for(ll i=0;i<5;i++){
		sol+=res.x[0][i]*base[i]%m;
	}
    cout << sol% m;

    return 0;
}
 

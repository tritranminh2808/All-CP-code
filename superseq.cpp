#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=666013;
struct matran {
    ll x[101][101];
    friend matran operator*(matran a, matran b) {
        matran c;
        for (ll i = 0; i < 101; i++) {
            for (ll j = 0; j < 101; j++) {
                c.x[i][j] = 0;
                for (ll k = 0; k < 101; k++) {
                    c.x[i][j] += a.x[i][k] * b.x[k][j];
                    c.x[i][j] %= mod;
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
int n,h,k;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    ll n;
    cin >> n>> h >> k;
//    n-=2;
    matran a;
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) a.x[i][j]=0;
    for(int i=0;i<=h;i++){
    	for(int j=max(0,i-k);j<=min(h,i+k);j++){
    		a.x[i][j]=1;
		}
	}
    matran res = bp(a,n-1);
    /*for(int i=0;i<h;i++){
    	for(int j=0;j<h;j++) cout << a.x[i][j] << " ";
    	cout << "\n";
	}*/
    cout << res.x[0][h];

    return 0;
}
 

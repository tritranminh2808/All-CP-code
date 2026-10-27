#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll m=1e9+7;
struct matran {
    ll x[2][2];
    friend matran operator*(matran a, matran b) {
        matran c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 2; k++) {
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
        tmp = tmp * a;
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    if(n==0){
    	cout << 0;
    	return 0;
	}
	if(n==1){
		cout << 19; return 0;
	}
//    n-=2;
    matran a;
    a.x[0][0] = 19;
    a.x[0][1] = 7;
    a.x[1][0] = 6;
    a.x[1][1] = 20;

    matran res = bp(a,n);

    cout << res.x[0][0] % m;

    return 0;
}
 

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll m=111539786;
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
    ll t; cin >> t;
    matran a;
    a.x[0][0] = 1;
    a.x[0][1] = 1;
    a.x[1][0] = 1;
    a.x[1][1] = 0;
	while(t--){
		int r;cin >> r;
		matran r1=bp(a,r);
		cout << (r1.x[0][0]+m)%m << "\n";
	}
    return 0;
}
 

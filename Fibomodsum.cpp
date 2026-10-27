#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll m=1e9+7;
struct matran {
    ll x[3][3];
    friend matran operator*(matran a, matran b) {
        matran c;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 3; k++) {
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
    if (n%2)  tmp = tmp * a;
    
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    matran a;
    a.x[0][0] = 1;
    a.x[0][1] = 1;
    a.x[0][2] = 0;
    a.x[1][0] = 1;
    a.x[1][1] = 0;
    a.x[1][2] = 0;
    a.x[2][2] = 1;
    a.x[2][1] = 1;
    a.x[2][0] = 1;
    while(t--){
    	int l,r; cin >> l >> r;
    	if(l==0) {
    		matran res2=bp(a,r);
    		cout << res2.x[2][0] << "\n";
    		continue;
		}
		l--;
		r--;
    	matran res=bp(a,l-1);
    	matran res2=bp(a,r);
    	cout << (res2.x[2][0]-res.x[2][0]+m)%m << "\n";
	}

    return 0;
}
 

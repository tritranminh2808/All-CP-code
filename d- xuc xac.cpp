#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll m=1e9+7;
struct matran {
    ll x[6][6];
    friend matran operator*(matran a, matran b) {
        matran c;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 6; k++) {
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
//    n-=2;
    matran a;
   	for(int i=0;i<6;i++) a.x[i][0]=1;
   	for(int i=1;i<6;i++){
   		for(int j=0;j<6;j++){
   				if(j==i-1) a.x[j][i]=1;
   				else a.x[j][i]=0;
		   }
	}
    matran res = bp(a,n);

    cout << res.x[0][0] % m;

    return 0;
}
 

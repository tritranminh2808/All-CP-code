#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull mod = 1e9+7;
ull gt(ull n){
	ull s=1;
	for(ull i=2;i<=n;i++) {
		s*=i;s%=mod;
	}
	return s%mod;
}
ull mul(ull a, ull b, ull m){
	if(b==0) return 0;
	ull t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
ull power(ull a,ull b, ull m) {
    if (b == 0) return 1;

    ull half = power(a, b/2, m);
   
    if (b%2==0) return mul(half,half,m);
    else return mul(half,mul(half,a,m),m);
}
signed main() {
//	freopen("squares.inp","r",stdin);
//	freopen("squares.out","w",stdout);
    ull n,m;
    cin >> n>>m;
    ull res=gt(n-1)*power(gt(m-1),mod-2,mod)%mod;
	cout << res*power(gt(n-m),mod-2,mod)%mod;
}


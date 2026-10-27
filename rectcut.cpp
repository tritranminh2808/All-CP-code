#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull mod = 123456789;
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
int main() {
//	freopen("squares.inp","r",stdin);
//	freopen("squares.out","w",stdout);
    ull n,m;
    cin >> n>>m;
	cout << power(2,n-1,mod)*power(2,m-1,mod)%mod;
}


#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
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
bool check(ull n){
	ull k=sqrt(n);
	if(k*k==n) return true;
	else return false;
}
int mod=123456789;
ull sol=1;
int main() {
	
    ull n; cin >> n;
    sol=mul(sol,power(2,n-1,mod),mod);
	cout << sol;
    return 0;
}


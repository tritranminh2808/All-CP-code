#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
int dem(int n, int a){
	n=n-n%a;
	return n/a;
}
int cook(int n, int a , int b, int ngu){
	int sol=0;
	sol+=dem(n,lcm(a,b))-dem(n,lcm(a,lcm(b,ngu)));
	return sol;
}
signed main(){
////	freopen("test.inp","r",stdin);
	int n;
	while(cin >> n){
		int p, q, r; cin >> p >> q >> r;
		cout << cook(n,p,q,r)+cook(n,p,r,q)+cook(n,r,q,p) << "\n";
	}
	return 0;
}

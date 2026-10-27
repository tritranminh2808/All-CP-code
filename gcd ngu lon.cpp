#include <bits/stdc++.h>
#define int long long
using namespace std;
int pre[100005],a[100005];
int sech(int n){
	int res=n;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			while(n%i==0) n/=i;
			res-=res/i;
		}
	}
	if(n!=1) res-=res/n;
	return res;
}
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
signed main(){
	int t;cin >> t;
	while(t--){
		int x,z; cin >> x>> z;
		cout << sech(z/gcd(x,z)) << "\n";
	}
	return 0;
}

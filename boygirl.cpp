#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int gt(int n){
	int s=1;
	for(int i=2;i<=n;i++){
		s*=i;s%=mod;
	}return s;
}
signed main(){
	int n,m; cin >> n >> m;
	if(min(m,n)<max(n,m)-1) {
		cout <<0;
		return 0;
	}
	if(n!=m)cout << gt(n)%mod*gt(m)%mod;
	else cout << 2*gt(n)%mod*gt(m)%mod;
	return 0;
}

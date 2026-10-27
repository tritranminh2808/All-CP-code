#include <bits/stdc++.h>
// #define int long long
using ll= long long;
using namespace std;
const ll mod=1e9+7, mod2=1e9+9;
ll power[1000005],power2[1000005],hashT[1000005],hashT2[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin >> n >> q;
	const int c=257,c2=313;
	power[0] = 1;
	power2[0]=1;
	for(int i = 1; i <= 1e6; i++){
        power[i] = power[i - 1] * c % mod;
	    power2[i] = power2[i - 1] * c2 % mod2;
    }
	string a; 
	cin >> a;
	a="!"+a;
	for (int i = 1; i <= n; i++) {
        hashT[i] = (hashT[i - 1] * c + a[i]  + 1) % mod;
	    hashT2[i] = (hashT2[i - 1] * c2 + a[i] + 1) % mod2;
    }
	while(q--){
		int l,r,u,v;
        cin >> l>> r >> u >> v;
		ll k1=(hashT[r]-hashT[l-1]*power[r-l+1])%mod;
		ll k2=(hashT[v]-hashT[u-1]*power[v-u+1])%mod;
		if(k1<0) k1+=mod;
		if(k2<0) k2+=mod;
		// ll k3=(hashT2[r]-hashT2[l-1]*power2[r-l+1])%mod2;
		// ll k4=(hashT2[v]-hashT2[u-1]*power2[v-u+1])%mod2;
		// if(k3<0) k3+=mod2;
		// if(k4<0) k4+=mod2;
		if(k1==k2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
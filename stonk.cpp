#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int share[500005],last[500005],res[500005];
//int ST[(const int)4e6+5];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin >> n >> q;
	int S=0;
	while(q--){
		int z; cin >> z;
		if(z==1){
			int u,v; cin >> u >> v;
			int d=(S-last[u]+mod)%mod;
			res[u]=(res[u]+share[u]*d)%mod;
			int x=v%mod;
			if(x<0) x+=mod;
			share[u]=(share[u]+x)%mod;
			last[u]=S;
		}
		else if(z==2){
			int x; cin >> x;
			S=(S+x)%mod;
		}
		else{
			int u; cin >> u;
			int d=(S-last[u]+mod)%mod;
			res[u]=(res[u]+share[u]*d)%mod;
			cout << res[u] << "\n";
			res[u]=0;
			last[u]=S;
		}
	}
	return 0;
}

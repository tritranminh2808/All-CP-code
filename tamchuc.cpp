#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int a[1000005],pre[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin >> n >> q;
	int cur=1;
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		a[i]=cur%mod;
		a[i]=max(a[i]-x+mod,(int)0)%mod;
		cur=a[i];
		cur=cur*2%mod;
	}
	for(int i=1;i<=n;i++) pre[i]=(pre[i-1]+a[i]+mod)%mod;
	while(q--){
		int l,r; cin>> l>> r;
		cout << pre[r]-pre[l-1] << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n,q; 
long long a[1000005],prea[1000005],preb[1000005],prec[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];
	while (q--){
		int x,l;
		cin >> x >> l;
		prea[x]++;
		prea[x+l]--;
		preb[x]-=2LL*(x+l);
		preb[x+l]+=2LL*(x+l);
		prec[x]+=1ll*x*x+2ll*l*x+1ll*l*l;;
		prec[x+l]-=1ll*x*x+2ll*l*x+1ll*l*l;
	}
	for(int i=1;i<=n;i++){
		prea[i]+=prea[i-1];
		preb[i]+=preb[i-1];
		prec[i]+=prec[i-1];
		cout << a[i]+prea[i]*i*i+preb[i]*i+prec[i] << " ";
	}
}

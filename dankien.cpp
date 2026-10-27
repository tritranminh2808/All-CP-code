#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],x[1000005],pre[1000005], pre2[1000005];
int sol=1e18;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		pre[i]=pre[i-1]+a[i];
//		T+=a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> x[i];
		pre2[i]+=pre2[i-1]+a[i]*x[i];
	}
	for(int i=1;i<=n;i++){
		int tt=x[i]*pre[i]-pre2[i]-x[i]*(pre[n]-pre[i])+pre2[n]-pre2[i];
		sol=min(sol,tt);
	}
	cout << sol;
	return 0;
}

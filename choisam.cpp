#include <bits/stdc++.h>
#define int long long
using namespace std;
struct sech{
	int p,q,r;
};
const int mod=1e9+7;
sech dp[1000005],pre[1000005];
signed main(){
	int P,Q,R,n; cin>> n>> P >> Q >> R;
	for(int i=1;i<=n;i++){
		if(i<=P) dp[i].p++;;
		dp[i].p+=(pre[i-1].q-pre[max((int)0,i-P-1)].q+pre[i-1].r-pre[max((int)0,i-P-1)].r+mod)%mod;
		if(i<=Q) dp[i].q++;;
		dp[i].q+=(pre[i-1].p-pre[max((int)0,i-Q-1)].p+pre[i-1].r-pre[max((int)0,i-Q-1)].r+mod)%mod;
		if(i<=R) dp[i].r++;;
		dp[i].r+=(pre[i-1].p-pre[max((int)0,i-R-1)].p+pre[i-1].q-pre[max((int)0,i-R-1)].q+mod)%mod;
		pre[i].p=(pre[i-1].p+dp[i].p+mod)%mod;
		pre[i].q=(pre[i-1].q+dp[i].q+mod)%mod;
		pre[i].r=(pre[i-1].r+dp[i].r+mod)%mod;
	}
//	for(int i=1;i<=n;i++)cout << dp[i].p << " " << dp[i].q << " " << dp[i].r << "\n";
	cout << (dp[n].p+dp[n].q+dp[n].r+mod)%mod;
	return 0;
}

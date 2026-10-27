#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000005];
const int mod=1e9+7;
signed main(){
	int a,b,n; cin >> a >> b >> n;
	dp[0]=a;
	dp[1]=b;
	for(int i=2;i<=n;i++) dp[i]=(dp[i-1]%mod+dp[i-2]*2%mod+3*i*i%mod)%mod;
	cout << dp[n];
	return 0;
}

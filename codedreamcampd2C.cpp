#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int dp[100005][15];
int sol=0,cnt=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k; cin >> n >> k;
	dp[1][1]=1;
	for(int i=1;i<=n;i++) dp [i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++) {
			for(int k=0;k<=j;k++){
				dp[i][j]=(dp[i][j]+dp[i-1][k]*dp[i-1][j-k]%mod)%mod;
			}
		}
	}
	cout << dp[n][k]%mod;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
bool a[105][105];
int dp[3000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin >> a[i][j];
	}
	dp[0]=1;
	for(int mask=0;mask<(1<<n);mask++){
		int cnt=__builtin_popcount(mask);
		for(int i=0;i<n;i++){
			if(!(mask&(1<<i))&&a[cnt][i]==1){
				dp[mask|(1<<i)]=(dp[mask|(1<<i)]+dp[mask])%mod;
			}
		}
	}
	cout << dp[(1<<n)-1];
	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int dp[100005],a[100005];
signed main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[1]=0;
	dp[2]=abs(a[1]-a[2]);
	for(int i=3;i<=n;i++){
		dp[i]=min(dp[i-1]+abs(a[i-1]-a[i]),dp[i-2]+abs(a[i-2]-a[i]));
	}
	cout << dp[n];
}

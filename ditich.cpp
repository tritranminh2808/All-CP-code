#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
struct pl{
	int mot,hai,ba,bon;
};
pl dp[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i+1];
	for(int i=1;i<=n+1;i++){
		dp[i].mot=dp[i-1].mot+a[i];
		if(i<2) dp[i].hai=-1e18;
		else dp[i].hai=max(dp[i-1].mot-a[i],dp[i-1].hai-a[i]);
		if(i<3) dp[i].ba=-1e18;
		else dp[i].ba=max(dp[i-1].hai+a[i],dp[i-1].ba+a[i]);
		if(i<4) dp[i].bon=-1e18;
		else dp[i].bon=max(dp[i-1].ba-a[i],dp[i-1].bon-a[i]);
	} 
	cout << max({dp[n+1].ba,dp[n+1].bon});
	return 0;
}

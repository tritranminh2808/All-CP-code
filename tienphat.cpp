#include <bits/stdc++.h>
#define int long long
using namespace std;
struct pl{
	int x,c;
};
int n;
pl a[3005];
long long sol=INT_MAX;
bool cmp(pl u, pl v){
	return u.x<v.x;
}
int dp[3005],pre[3005];
signed main(){
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i].x >> a[i].c;
		pre[i]=pre[i-1]+a[i].x;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i) cout << pre[i] << " ";
	dp[1]=a[1].c;
	sol=INT_MAX;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;++j){
			int cnt=(pre[i-1]-pre[j])-(i-1-j)*a[j].x;
			cout << cnt << " ";
			dp[i]=min(dp[i],dp[j]+a[i].c+cnt);
		}
	}
	for(int i=1;i<=n;i++){
//		cout << dp[i] << " ";
		sol=min(sol,dp[i]+(pre[n]-pre[i])-(n-i)*a[i].x);
	}
	cout << sol;
	return 0;
}

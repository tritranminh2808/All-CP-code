#include <bits/stdc++.h>
using namespace std;
int dp[100005],a[100005];
int main(){
	int n,h,d; cin >> n >> d >> h;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[1]=a[1];
	for(int i=2;i<=n;i++) dp[i]=100005;
	for(int i=2;i<=d;i++){
		for(int j=1;j<i;j++) {
			if(abs(a[j]-a[i])<=h) dp[i]=min(dp[i],dp[j]+a[i]);
		}
	}
	for(int i=d+1;i<=n;i++){
		for(int j=i-d;j<i;j++){
			if(abs(a[j]-a[i])<=h) dp[i]=min(dp[i],dp[j]+a[i]);
		}
	}
//	for(int i=1;i<=n;i++) cout << dp[i] << " ";
	cout << dp[n];
	return 0;
}

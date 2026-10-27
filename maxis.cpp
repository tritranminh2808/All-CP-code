#include <bits/stdc++.h>
using namespace std;
long long a[1005],dp[1005];
int main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		dp[i]=a[i];
		for(int j=1;j<i;j++) if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+a[i]);
	}
	long long sol=0;
	for(int i=1;i<=n;i++) sol=max(sol,dp[i]);
	cout << sol;
	return 0;
}

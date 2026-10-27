#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int a[p],dp[p];
int main(){
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	dp[1]=abs(a[0]-a[1]);
	for(int i=2;i<n;i++){
		dp[i]=min(dp[i-1]+abs(a[i-1]-a[i]),dp[i-2]+abs(a[i-2]-a[i]));
		
		
	}
	cout << dp[n-1];
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int p=1e3+5;
int sol=-9999999;
int a[p][p],dp[p][p];
int main(){
	int n,m;cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int i=1;i<=m;i++) {
		dp[0][i]=-1000000009;
		dp[m+1][i]=-1000000009;
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;++i) {
			dp[i][j]=max(dp[i-1][j-1],max(dp[i][j-1],dp[i+1][j-1]))+a[i][j];
			
		}
	}
	for(int i=1;i<=n;i++) sol=max(sol,dp[i][m]);
	cout << sol;
	return 0;
}

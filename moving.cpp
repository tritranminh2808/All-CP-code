#include <bits/stdc++.h>
using namespace std;
int a[2005][2005],dp[2005][2005];
int main(){
	int n,m; cin >> n >> m ;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) dp[i][j]=max({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]})+a[i][j];
	}
	int sol=-9999999;
	for(int i=1;i<=m;i++) sol=max(sol,dp[n][i]);
	cout << sol;
	return 0;
}

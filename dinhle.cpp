#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int a[100][100];
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	for(int i=0;i<=n;i++) dp[i][0]=-INT_MAX;
	for(int i=0;i<=m;i++) dp[0][i]=-INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	dp[1][1]=a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			if(i==1&&j==1) continue;
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
		}
	}
	cout << dp[n][m]-dp[1][1];
	return 0;
}

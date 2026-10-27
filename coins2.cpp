#include <bits/stdc++.h>
using namespace std;
long long dp[101][100001],dp2[101][100001];
long long mod=123456789;
int main(){
	freopen("coins2.inp","r",stdin);
	freopen("coins2.out","w",stdout);
	int n; cin>> n;
	dp[0][0]=1;
	for(long long j=0;j<=n;j++){
		for(long long i=1;i<=100;i++){
			if(j>=i*i) {
				dp[i][j]=(dp[i][j-i*i]+dp[i-1][j])%mod; 
			}
			
			else {
				dp[i][j]=dp[i-1][j];
			}
			
		}
	} 

	cout << dp[100][n] << "\n";

	return 0;
}

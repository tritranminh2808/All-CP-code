#include <bits/stdc++.h>
using namespace std;
long long dp[101][100001],dp2[101][100001];
long long mod=123456789;
int main(){
	int n; cin>> n;
	dp[0][0]=1;
	for(int i=1;i<=n;i++) dp[1][i]=1;
	for(long long j=1;j<=n;j++){
		for(long long i=2;i<=100;i++){
			if(j>=i*i) {
				dp[i][j]=(dp[i][j-i*i]+dp[i-1][j])%mod; 
			}
			
			else {
				dp[i][j]=dp[i-1][j];
			}
			
		}
	} 

	cout << dp[100][n] << "\n";
	for (int i = 1;i<=n;++i){
		dp2[1][i] = (long long)i;
	}
	for (int i = 1;i<=100;++i){
		dp2[i][0] = 0;
	}
	for(int i=1;i<=n;i++) dp2[1][i]=i;
	for(long long j=1;j<=n;j++){
		for(long long i=2;i<=100;i++){
			if((i*i)>j) dp2[i][j]=dp2[i-1][j];
			else dp2[i][j]=min(dp2[i][j-i*i]+1,dp2[i-1][j])%mod;
		}
	} 
	
	cout << dp2[100][n];
	return 0;
}

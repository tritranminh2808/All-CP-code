#include <bits/stdc++.h>
using namespace std;
const long long mod = 123456789;
long long dp[101][100001];
long long g[101][100001];
int main(){
	int n;
	cin >> n;
	dp[0][0] = 1;
	g[0][0] = 0;
	for (int j = 0;j<=n;++j){
		for (int i = 1;i<=100;++i){
			if (i*i > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = (dp[i-1][j] + dp[i][j-i*i])%mod;
			}
		}
	}
	for (int i = 1;i<=n;++i){
		g[1][i] = (long long)i;
	}
	for (int i = 1;i<=100;++i){
		g[i][0] = (long long)0;
	}
	for (int j = 1;j<=n;++j){
		for (int i = 2;i<=100;++i){
			if (i*i>j){
				g[i][j] = g[i-1][j];
			}else g[i][j] = min(g[i-1][j], g[i][j-i*i] + 1)%mod;
		}
	}
	
	cout << dp[100][n] << "\n" << g[100][n];
}

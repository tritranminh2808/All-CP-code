#include <bits/stdc++.h>
using namespace std;
const long long p=1e5+5;
long long dp[200][p];
int main(){
	long long n,m; cin>> n >> m;
	vector < pair < long long , long long > > v(n+1);
	for(long long i=1;i<=n;i++) cin >> v[i].first >> v[i].second;
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(j>=v[i].first) {
				dp[i][j]=max(dp[i-1][j],v[i].second+dp[i-1][j-v[i].first]); 
			}
			
			else {
				dp[i][j]=dp[i-1][j];
			}
			
			
		}
	} 
	/*for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++) cout << dp[i][j] <<" ";
		cout << "\n";
	}*/
	cout << dp[n][m];
	//memset(dp,0,)
	return 0;
}


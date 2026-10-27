#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[105][105];
signed main(){
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	while(cin >> n){
//		memset(dp,INT_MAX,sizeof(dp));
		vector <int> a(n+1),pre(n+1);
		pre[0]=0;
		for(int i=1;i<=n;i++) {
			cin >> a[i];
			pre[i]=pre[i-1]+a[i];
			dp[i][i]=0;
		}
		for(int l=2;l<=n;l++){
			for(int i=1;i<=n-l+1;i++){
				int j=i+l-1;
				dp[i][j]=1e18;
				for(int k=i;k<j;k++){
					int lf=(pre[k]-pre[i-1])%100,rt=(pre[j]-pre[k])%100;
//					cout << lf << " " << rt << "\n";
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+lf*rt);
				}
			}
		}
		cout << dp[1][n] << "\n";
	}
	return 0;
}

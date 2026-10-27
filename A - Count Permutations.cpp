#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin >> t;
	while(t--){
		int n,k; cin >> n >> k;
		int dp[n][(1<<n)];
		for(int i=0;i<n;i++){
			for(int j=0;j<(1 << n);j++) dp[i][j]=0;
		}
		for(int i=0;i<n;i++) dp[i][1<<i]=1;
		for(int mask=1;mask<=(1<<n)-1;mask++){
			for(int i=0;i<=n-1;i++){
				if((1<<i)&mask) {
					for(int j=0;j<=n-1;j++){
						if(!((1<<j)&mask)&&(abs(i-j)<=k)) dp[j][mask|(1<<j)]+=dp[i][mask];
					}
				}
			}
		}
		int sol=0;
		for(int i=0;i<=n-1;i++) sol+=dp[i][(1<<n)-1];
		cout << sol << "\n";
	}
	return 0;
}

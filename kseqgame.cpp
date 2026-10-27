#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[6][1006][1006];
const int p=1e6+6;
int a[p],b[p];
int m,n,k;
signed main(){
	cin >> n >> k;
	for(int i=0;i<6;i++){
		for(int j=0;j<1006;j++){
			for(int x=0;x<1006;x++) dp[i][j][x]=-1e16;
		}
	}
	for(int i=1;i<=n;++i) cin >> a[i] ;
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int x=1;x<=k;++x){
		for(int y=x;y<=n;++y){
			for(int j=x;j<=n;j++) {
				if(x==1){
					dp[x][y][j]=max(a[y]*b[j],max(dp[x][y-1][j],dp[x][y][j-1]));
				}
				else dp[x][y][j]=max(dp[x-1][y-1][j-1]+a[y]*b[j],max(dp[x][y-1][j],dp[x][y][j-1]));
			}
		}
	}
	cout << dp[k][n][n];
	

}


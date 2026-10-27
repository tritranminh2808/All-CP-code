#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")
//#define int long long
using namespace std;
const int mod=1e9+7;
int a[4005],b[4005];
int c[4005][4005];
long long dp[4005][4005],dc[4005][4005],dr[4005][4005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m,n,k; cin >> n >> m >>k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int j=1;j<=m;j++) cin >> b[j];
	dp[1][1]=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
        	c[i][j]=(a[i]+b[j])%k+1;
            if(i>1) dr[i][j]=(dr[i][j]+dr[i-1][j])%mod;
            if(j>1) dc[i][j]=(dc[i][j]+dc[i][j-1])%mod;
            dp[i][j]=(dp[i][j]+dr[i][j]+dc[i][j])%mod;
            int h=min(n,i+c[i][j]);
            if(i+1<=n){
                dr[i+1][j]=(dr[i+1][j]+dp[i][j])%mod;
                if(h+1<=n) dr[h+1][j]=(dr[h+1][j]-dp[i][j]+mod)%mod;
            }
            h=min(m,j+c[i][j]);
            if(j+1<=m){
                dc[i][j+1]=(dc[i][j+1]+dp[i][j])%mod;
                if(h+1<=m) dc[i][h+1]=(dc[i][h+1]-dp[i][j]+mod)%mod;
            }
        }
	}
    cout << dp[n][m]%mod;
    return 0;
}

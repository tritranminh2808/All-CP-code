#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[2][10005];
int edit[10005],a[10005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   int n,c; cin >>n>> c;
   for(int i=1;i<=n;i++) {
   		cin >> a[i];
   		edit[i]=a[i];
   }
   dp[0][1]=(a[2]-a[1])*c;
   dp[1][1]=dp[0][1];
   if(a[2]<=a[1]) dp[1][1]=dp[0][1];
	
    else {
    	for(int i=a[1]+1;i<=a[2];i++) {
    		if(c*(a[2]-i)+(i-a[1])*(i-a[1])<=dp[1][1]){
    			dp[1][1]=c*(a[2]-i)+(i-a[1])*(i-a[1]);
    			edit[1]=i;
			}
		}
	}
	for(int i=2;i<n;i++){
		dp[0][i]=min(dp[0][i-1],dp[1][i-1])+abs(a[i+1]-a[i])*c;
		dp[1][i]=76437632732467;
		for(int j=a[i]+1;j<=max(a[i-1],a[i+1]);j++){
			if(c*abs(a[i+1]-j)+c*abs(a[i-1]-j)+(j-a[i])*(j-a[i])<=dp[1][i]){
    			dp[1][i]=c*abs(a[i+1]-j)+c*abs(a[i-1]-j)+(j-a[i])*(j-a[i]);
    			edit[i]=j;
			}
		}
	}
	for(int i=1;i<n;i++) cout << dp[0][i] << " " << dp[1][i] << " " << edit[i] << "\n";
//	cout << dp[0][1] << " " << dp[1][1] << " " << edit[1];
    return 0;
}


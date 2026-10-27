#include <bits/stdc++.h>
using namespace std;
int dp[1000005],dp2[1000005];
int main(){
	freopen("str.inp","r",stdin);
	freopen("str.out","w",stdout);
	string s; cin >> s;
	if(s[0]=='A') {
		dp[0]=0;
		dp2[0]=1;
	}
	else {
		dp[0]=1;
		dp2[0]=0;
	}
	for(int i=1;i<s.length();i++){
		if(s[i]=='A') {
			dp[i]=min(dp[i-1],dp2[i-1]+2);
			dp2[i]=min(dp2[i-1]+1,dp[i-1]+1);
		}
		else {
			dp[i]=min(dp[i-1]+1,dp2[i-1]+1);
			dp2[i]=min(dp2[i-1],dp[i-1]+2);
		}
	}
	cout << dp[s.length()-1];
	return 0;
}

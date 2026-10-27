#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[(const int) 1e6+5];
signed main(){
	string s;
	cin >> s;
	dp[0]=0;
	for(int i=1;i<s.length();i++){
		int j = dp[i-1];
		while(j>0&&s[i]!=s[j]){
			j = dp[j-1];
		}
		if(s[i]==s[j])j++;
		dp[i] = j;
	}
	for(int i=0;i<s.length();++i) cout << dp[i] << " ";
	return 0;
}

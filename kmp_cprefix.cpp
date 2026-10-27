#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[(const int) 1e6+5],sol[1000005],kmp[1000005];
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
    for(int i=1;i<=s.length();++i) kmp[i]=dp[i-1];
	for(int i=1;i<=s.length();++i) {
		sol[1]++;
		sol[kmp[i]+1]--;
	}
	for(int i=1;i<=s.length();i++){
		sol[i]+=sol[i-1];
		cout << sol[i];
	}
	return 0;
}

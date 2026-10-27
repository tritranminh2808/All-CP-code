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
		while(j>0 and s[i]!=s[j]){
			j = dp[j-1];
		}
		if(s[i]==s[j])j++;
		dp[i] = j;
	}
	int x=s.length()-dp[s.length()-1];
	if(s.length()%x!=0) {
		cout << s;
		return 0;
	}
	for(int i=0;i<s.length()-dp[s.length()-1];i++) cout << s[i];
//	cout << s.substr(0,s.length()-dp[s.length()-1]);
	return 0;
}

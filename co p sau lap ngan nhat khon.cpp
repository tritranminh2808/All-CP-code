#include <bits/stdc++.h>
//#define int long long
using namespace std;
int dp[(const int) 1e6+5];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		for(int i=0;i<=1000000;i++) dp[i]=0;
		string s,base;
		cin >> base;
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
		string sol;
		for(int i=0;i<s.length()-dp[s.length()-1];i++)sol+=s[i];
		int d=base.length();
		bool chck=0;
		while(d--){
			char c=base[0];
			base.erase(base.begin());
			base+=c;
			if(base==sol) {
				cout << "YES";
				chck=1;
				break;
			}
		}
		if(chck==0) cout << "NO";
		cout << "\n";
	}
//	cout << s.substr(0,s.length()-dp[s.length()-1]);
	return 0;
}


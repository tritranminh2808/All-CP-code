#include <bits/stdc++.h>
using namespace std;
int pre[600005];
int ans[600005];
int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		int j=pre[i-1];
		while(j>0&&s[i]!=s[j]) j=pre[j-1];
		if(s[i]==s[j]) j++;	
		pre[i]=j;
	}
	for(int i=0;i<s.length();i++) ans[i]++;
	for(int i=s.length()-1;i>=0;i--) ans[pre[i]]+=ans[i];
	for(int i=0;i<s.length();i++) cout << ans[i] << " ";
	return 0;
}

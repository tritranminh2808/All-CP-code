#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int c=31;
const int mod=1e9+7;
int hashP (string s){
	int hs=0;
	for(int i=0;i<s.length();i++) hs+=(hs*c+s[i]-'a'+1)%mod;
	return hs;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n;
	while(n--){
		string s; cin >> s;
		mp[hashP(s)]=1;
	}
	cin >> m;
	while(m--){
		string s; cin >> s;
		if(mp[hashP(s)]==1) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

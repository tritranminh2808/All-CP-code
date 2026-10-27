#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <string> V;
bool check(string x){
	for(auto i : V)	if(x==i) return true;
	return false;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	int n; cin >> n;
	int t;cin>> t;
	V.push_back("ABC");
	V.push_back("ACB");
	V.push_back("BAC");
	V.push_back("BCA");
	V.push_back("CAB");
	V.push_back("CBA");
	while(t--){
		unordered_map<string,bool> mp;
		string s;
		cin >> s;
		for(int i=0;i<s.length()-2;i++){
			string k;
			k+=s[i];k+=s[i+1];k+=s[i+2];
			if(check(k)){
				if(mp[k]!=0) continue;
				mp[k]=1;
				i+=2;
			}
		}
		if(mp.size()<6)cout << "NO\n";
		else cout << "YES\n";
	}
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,base=257;
int hs(string s){
	int hh=0;
	for(int i=0;i<s.length();i++) hh=(hh*base+s[i]+1)%mod;
	return hh;
}
signed main(){
	freopen("input.inp","r",stdin);
	freopen("output.inp","w",stdout);
	string s; 
	getline(cin,s);
	int cnt=1;
	string cur;
	vector <int> v;
	for(int i=0;i<s.length();i++){
//		if(s[i]>='A'&&s[i]<='Z') cout << s[i];
		if(s[i]>='a'&&s[i]<='z') cur+=char(s[i]-32);
		if(s[i]>='A'&&s[i]<='Z') cur+=s[i];
		if(s[i]==',') {
			v.push_back(hs(cur));
			cur.clear();
		}
		
	}
	cout << "{";
	for(auto i : v) cout << i << ",";
	cout << "}";
}

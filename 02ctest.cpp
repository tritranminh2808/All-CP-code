#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,base=31;
int hasht[10005],power[10005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	int n; cin >> n;
	power[0]=1;
	for(int i=1;i<=10000;i++) power[i]=power[i-1]*base%mod;
	int t;cin>> t;
	while(t--){
		unordered_map<int,bool> mp;
		string s; cin >> s;
		for(int i=0;i<=s.length();i++) hasht[i]=0;
		int n=s.length();
		s='!'+s;
		int h=0;
		for(int i=1;i<=n;i++) h=(h*base+s[i]-'A'+1)%mod;
		cout << h << endl;
	}
}

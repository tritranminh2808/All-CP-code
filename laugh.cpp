#include <bits/stdc++.h>
#define hoangnam v
#define int long long
using namespace std;
int power[100005],hasht[100005],dp[100005];
const int mod=3e7+7,base=257;
bool cmp(pair <int,int> a, pair <int, int > b){
	if(a.first==b.first) return a.second < b.second;
	return a.first < b.first;
}
int mp[30000005];
int sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	power[0]=1;
	for(int i=1;i<=10000;i++) power[i]=power[i-1]*base%mod;
	int q; cin >> q;
	string s;
	cin >> s;
	s=' '+s;
	int n=s.length();
	for(int i=1;i<=n;i++) hasht[i]=(hasht[i-1]*base+s[i]+1)%mod;
	vector <pair <int, int > > hoangnam;
	while(q--){
		string k; cin >> k;
		int so=0;
		for(int i=0;i<k.length();i++) so=(so*base+k[i]+1)%mod;
		mp[so]=1;
//		cout << so << endl;
	}
	int sol=0;
	for(int i=1;i<=n;i++){
		for(int j=max((int)1,i-30);j<=i;j++){
			int k=(hasht[i]-power[i-j+1]*hasht[j-1])%mod;
			if(k<0) k+=mod;
			if(mp[k]==1) dp[i]=max(dp[i],dp[j-1]+i-j+1);
		}
	}
	for(int i=0;i<=n;i++) sol=max(sol,dp[i]);
	cout << sol;
	return 0;
}


#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("03,unroll-loops")
using namespace std;
const int  p=1e6+5;
int  a[p]; int  pre[p];
int sol=0;
signed  main(){
	freopen("COIN.inp","r",stdin);
	freopen("COIN.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int  n; cin >> n;
	for(int  i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i]==0) a[i]=-1;
		pre[i]=pre[i-1]+a[i];
		
	}
//	for(int i=1;i<=n;i++) cout << pre[i] << " ";
	unordered_map<int,int> mp;
	mp[0]++;
	int sol=0;
	for(int i=1;i<=n;i++){
		sol+=mp[pre[i]];
		mp[pre[i]]++;
	}
	cout << max(sol,(int)0);
	return 0;
}

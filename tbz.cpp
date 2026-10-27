#include <bits/stdc++.h>
#define int long long
int a[10000005],pre[10000005];
using namespace std;
signed main(){
//	freopen("szero.inp","r",stdin);
//	freopen("szero.out","w",stdout);
	int n; cin >>  n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	map<int,int> mp;
	mp[0]=1;
	int sol=-1;
	for(int i=0;i<=n;i++){
		sol+=mp[pre[i]];
		mp[pre[i]]++;
	}
//	cout << mp[0];
	cout << max(sol,(long long)0);
	return 0;
}


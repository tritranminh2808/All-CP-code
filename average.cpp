#include <bits/stdc++.h>
#define int long long
int a[1000005],pre[1000005];
using namespace std;
signed main(){
	int n,k; cin >>  n >> k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]-=k;
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	unordered_map<int,int> mp;
	int sol=-1;
	for(int i=0;i<=n;i++){
		if(mp[pre[i]]) sol=max(sol,i-mp[pre[i]]);
		else mp[pre[i]]=i;
		
	}
	cout << sol;
	return 0;
}


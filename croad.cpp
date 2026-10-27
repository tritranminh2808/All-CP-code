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
	mp[0]=0;
	int sol=-1,res=0;
	for(int i=1;i<=n;i++){
		if(pre[i]==0){
			sol=i;res=1;continue;
		}
		
		if(mp[pre[i]]){
		//	cout << pre[i] << " " << i << " " << mp[pre[i]] << "\n";
			if(i-mp[pre[i]]>sol){
				sol=i-mp[pre[i]];
				res=mp[pre[i]]+1;
			}
		}
		else mp[pre[i]]=i;
	}
	if(sol==-1) cout << 0;
	else cout << res << " " << sol;
	return 0;
}


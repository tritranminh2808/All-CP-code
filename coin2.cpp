#include <bits/stdc++.h>
#define int long long
int a[1000005],pre[1000005];
using namespace std;
signed main(){
	
	int k ,n;cin >> n >> k;
	string s; cin >> s;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='O') a[i]=1;
		else a[i]=-k;
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		//cout << pre[i] << " ";
	}
	unordered_map<int,int> mp;
	mp[0]=0;
	int sol=-1;
	for(int i=1;i<=n;i++){
		if(pre[i]==0){
			sol=i;continue;
		}
		
		if(mp[pre[i]]){
		//	cout << pre[i] << " " << i << " " << mp[pre[i]] << "\n";
			if(i-mp[pre[i]]>sol) sol=i-mp[pre[i]];
		}
		else mp[pre[i]]=i;
	}
	if(sol==-1) cout << 0;
	else cout << sol;
	return 0;
}


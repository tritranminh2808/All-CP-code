#include<bits/stdc++.h>
#define int long long
using namespace std;
int pre[100005];
signed main(){
	int t; cin >> t;
	while(t--){
		for(int i=0;i<100005;i++) pre[i]=0;
		int n,k; cin >> k>>n;
		vector <int> a(n+1);
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
		for(int i=1;i<=n;i++) pre[i]%=k;
		unordered_map<int,int> mp;
		mp[0]=1;
		int sol=0;
		for(int i=1;i<=n;i++){
			if(mp[pre[i]]) sol+=mp[pre[i]];
			mp[pre[i]]++;
		}
		cout << sol <<"\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#define int long long
int a[10005],pre[10005];
using namespace std;
signed main(){
	freopen("kavg.inp","r",stdin);
	freopen("kavg.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--){
		int n,k; cin >>  n >> k;
		for(int i=0;i<=n;i++) {
			pre[i]=0;
			a[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]-=k;
		}
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]+a[i];
		}
		unordered_map<int,int> mp;
		mp[0]=0;
		bool check=0;
		for(int i=1;i<=n;i++){
			if(mp[pre[i]]) {
				check=1;
				break;
			}
			mp[pre[i]]=i;
		}
		if(check==0) cout << "NO\n";
		else cout << "YES\n";
	}
	
	return 0;
}


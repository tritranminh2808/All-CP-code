#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005],f[1005];
const int base=1e6+3,mod=1e9+7;
signed main(){
//	freopen("tesst.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >>n;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++)cin >> a[i];
	unordered_map<int, int > mp;
	int sol=0;
	while(1){
		for(int i=1;i<=n;i++) f[i]=a[f[i]];
		int hs=0;
		for(int i=1;i<=n;i++) hs=(hs*base+f[i]+1)%mod;
//		cout << hs << endl;
		if(mp[hs]==1) break;
		mp[hs]=1;
		sol++;
	}
	cout << sol;
	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	map<int,int> mp;
	for(int i=0;i<64;i++){
		mp[1<<i]=1;
		mp[(1<<i)-1]=1;
	}
	while(t--){
		int n; cin >> n;
		if(mp[n]==1) {
			cout << -1 << "\n";
			continue;
		}
		else cout << (1<<(__lg(n)))-1 << "\n";
	}
	return 0;
	
}

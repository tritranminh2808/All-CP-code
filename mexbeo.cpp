#include <bits/stdc++.h>
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,x; cin >> t>>x;
	int mex=0;
	unordered_map<int,int> mp;
	while(t--){
		int q; cin >> q;
		mp[q%x]++;
		while(mp[mex%x]>mex/x) mex++;
		cout << mex << "\n";
	}
	return 0;
}


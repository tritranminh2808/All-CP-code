#include <bits/stdc++.h>
#define int long long
using namespace std;
struct pl{
	int val,l,r;
};
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(n);
		int sol=1e18;
		vector <pl> v;
		for(int i=0;i<n;i++) cin >> a[i];
		v.push_back({a[0],0,0});
		for(int i=1;i<n;i++){
			if(a[i]==v[v.size()-1].val) v[v.size()-1].r++;
			else v.push_back({a[i],i,i});
		}
		for(auto i:v) sol=min(sol,i.val*(i.l+n-i.r-1));
		
		cout << sol << "\n";
	}
	return 0;
	
}

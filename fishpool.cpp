#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("fishpool.inp","r",stdin);
	freopen("fishpool.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,w,m; cin >> n>>w>>m;
		vector <int> v(n);
		for(int i=0;i<n;i++) cin >>v[i];
		sort(v.begin(),v.end());
		int sol=0;
		if(w<v[0]) cout <<"-1\n";
		else {
			while(w<m){
				if(w>=v[v.size()-1])w+=v[v.size()-1];
				else w+=v[upper_bound(v.begin(),v.end(),w)-v.begin()-1];
				sol++;
			}
			cout << sol << "\n";
		}
		
	}
}

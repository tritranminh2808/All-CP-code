#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		if(n==m){
			cout << "0\n";
			continue;
		}
		if(m%n!=0){
			cout << "-1\n";
			continue;
		}
		int k=m/n;
		vector <int> sol;
		int cur=1;
		bool chk=0;
		while(k!=1){
			int g=__gcd(n,k);
			if(g==1){
				cout << "-1\n";
				chk=1;
				break;
			}
			else {
				n*=g;
				k/=g;
				sol.push_back(g);
			}
		}
		if(!chk){
			cout << sol.size() << " ";
			for(auto i:sol) cout << i << " ";
			cout << "\n";
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,m,k; cin >> n >> m >> k;
		vector <int> v(n),a(m),q(k);
		for(int i=0;i<m;i++) cin >> a[i];
		vector <bool> sol(m);
		for(int i=0;i<k;i++) {
			cin >> q[i];
			sol[q[i]-1]=1;
		}
		if(n>k+1){
			for(int i=0;i<m;i++) cout << "0";
			cout << "\n";
		}
		else if(n==k){
			for(int i=0;i<m;i++) cout << "1";
			cout << "\n";
		}
		else{
			
			for(int i=0;i<m;i++){
				if(sol[i]==1) cout << "0";
				else cout << "1";
			}
			cout << "\n";
		}
		
		
	}
	return 0;
}

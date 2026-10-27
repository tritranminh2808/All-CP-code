#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int a; cin >> a;
		int sol=1;
		while(a>3){
			a/=4;
			sol*=2;
		}
		cout << sol << "\n";
	}
	return 0;
}

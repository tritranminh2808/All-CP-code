#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(n);
		for(int i=0;i<n;i++) cin >> a[i];
		int sol=0;
		unordered_map<int, int > mp;
		for(int i=0;i<n;i++){
			int mask=0;
			int x=a[i];
			while(x!=0){
				mask|=1<<(x%10);
				x/=10;
			}
			mp[mask]++;
		}
		for(int i=0;i<=9;i++){
			for(int mask=0;mask<(1<<20);mask++){
				if((mask>>i)&1) mp[mask]+=mp[mask-(1<<i)];
			}
		}
		for
		cout << sol << "\n";
 	}
	return 0;
}

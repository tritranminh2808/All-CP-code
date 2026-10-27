#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,k; cin>> n >> k;
		vector <int>  a(n+1);
		map <int, pair <int, int > > mp;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			mp[a[i]%k].first++;
			mp[a[i]%k].second=i;
		}
		bool check=0;
		for(auto i : mp){
			if(i.second.first<2){
				cout << "YES\n" << i.second.second << "\n";
				check=1;
				break;
			}
		}
		if(check==0) cout << "NO\n";
	}
	return 0;
}

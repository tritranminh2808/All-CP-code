#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(n),tru,cong;
		int k=21343242343432;
		bool check=0;
		for(int i=0;i<n;i++) {
			cin >> a[i];
			if(a[i]!=1&&a[i]!=-1) {
				k=a[i];
				check=1;
			}
			//else if(a[i]==1)cong.push_back(a[i]);
			else tru.push_back(a[i]);
		}
		set <int> sol,res;;
		res.insert(0);
		if(check) res.insert(k);
		int tong=0;
		for(auto i : tru){
			if(i==-1){
				tong+=i;
				sol.insert(tong);
				sol.insert(i);
				sol.insert(i+k);
			}
			else tong=0;
		}
		tong=0;
		for(auto i : tru){
			if(i==1){
				tong+=i;
				sol.insert(tong);
				sol.insert(i);
			}
			else if(i==k){
				for(auto i : sol){
					res.insert(k+i);
				}
			//	tong=0;
			}
			else tong=0;
		}
		for(auto i : sol){
			res.insert(i);
		//	if(check==1)res.insert(k+i);
		}
		cout << res.size() << "\n";
		for(auto i : res) cout << i << " ";
		cout << "\n";
	}
	return 0;
}

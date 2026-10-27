#include <bits/stdc++.h>
#define int long long
using ull=unsigned long long;
using namespace std;
vector <int> sol;
int ss=0,l=9999999,r=-9999999;
signed main(){
	int n; cin >> n;
	vector <int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v.begin(),v.end());
	for(int i=2;i<=v[0];i++){
		int mod=v[0]%i;
		bool check=0;
		for(auto j : v) {
			if(j%i!=mod) {
				check=1;break;
			}
		} 
		if(check==0) sol.push_back(i);
	}
	if(sol.empty()) cout << -1;
	else for(auto i : sol) cout<< i << " ";
	return 0;
}

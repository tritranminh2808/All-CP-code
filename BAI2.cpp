#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n; cin >> n;
	vector <int> a(n);
	vector < pair <int, int > > sol;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++) if(a[i]==a[j]) sol.push_back({i+1,j+1});
	}
	cout << sol.size() << "\n";
	for(auto i : sol) cout << i.first << " " << i.second << "\n";
	return 0;
}

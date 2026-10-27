#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int > a, pair <int, int > b){
	return a.first < b.first;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
//		vector <int> v[n];
		vector <pair <int, int > > cook;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int x; cin >> x;
//				v[i].push_back(x);
				cook.push_back({x,i+1});
			}
		} 
		bool sech=0;
		sort(cook.begin(),cook.end(),cmp);
		for(int i=0;i<n;i++){
			int base=cook[i].second;
			for(int j=i+n;j<cook.size();j+=n) {
				if(cook[j].second!=base){
					sech=1;
					break;
				}
			}
			if(sech==1) break;
		}
		if(sech==1) cout << -1;
		else for(int i=0;i<n;i++) cout << cook[i].second << " ";
		cout << "\n";
	}
	return 0;
}

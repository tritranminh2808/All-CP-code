#include <bits/stdc++.h>
using namespace std;
int f[400005];
bool check(vector <int> v){
	for(int i=0;i<v.size()-1;i++) if(v[i+1]<v[i]) return false;
	return true;
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,m1,m2;
		cin >> n >> m1>> m2;
		vector <pair <int, int > > f(m1),g(m2);
		map<pair<int,int>, bool> mp,mp2;
		for(int i=0;i<m1;i++){
			cin>> f[i].first >> f[i].second;
			mp2[{f[i].first,f[i].second}]=1;
		}
		for(int i=0;i<m2;i++){
			cin>> g[i].first >> g[i].second;
			mp[{g[i].first,g[i].second}]=1;
		}
		int cnt=0;
		for(auto i : f){
			if(mp[{i.first,i.second}]==1)continue;
			else cnt++;
		}
		for(auto i:mp){
			if(mp2[i.first]==1) continue;
			else cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}

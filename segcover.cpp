#include <bits./stdc++.h>
using namespace std;
bool cmp( pair <int,int> a, pair<int,int> b){
	if(a.first==b.first) return a.second < b.second;
	return a.first < b.first;
}
int main(){
	int n; cin>> n;
	vector <pair <int ,int > > v;
	for(int i=0;i<n;i++){
		int l,r; cin >> l >> r;
		v.push_back({l,r});
	}
	sort(v.begin(),v.end(),cmp);
	vector < pair <int,int> > s;
	for(int i=1;i<n;i++){
		if(v[i].first!=v[i-1].first) s.push_back({v[i-1].first,v[i-1].second});
	}
	s.push_back({v[n-1].first,v[n-1].second});
	for(auto i : s) cout << i.first << " " << i.second << "\n";
	return 0;
}

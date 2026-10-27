#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair <int,int> a, pair <int, int > b){
	if(a.first==b.first) return a.second < b.second;
	return a.first < b.first;
}
int sol=0;
signed main(){
	vector < pair <int, int > > v;
	for(int i=1;i<=4;i++){
		int l,r; cin>> l >> r;
		v.push_back({l,r});
	}
	sort(v.begin(),v.end(),cmp);
	int l=v[0].first, r=v[0].second;
	for(int i=1;i<v.size();++i){
		if(v[i].first>=l&&v[i].first<=r){
			r=max(r,v[i].second);
		}
		else {
			sol+=r-l+1;
			l=v[i].first;
			r=v[i].second;
		}
	}
	cout << sol+r-l+1;
	return 0;
}

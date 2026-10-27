#include <bits/stdc++.h>
using namespace std;


bool cmp(pair <int,int > a, pair <int,int> b){
	if(a.second==b.second) return a.first < b.first;
	return a.second<b.second;
}
int main(){
	int n; cin >> n;
	vector <pair < int, int > > a(n);
	vector <pair < int, int > > f;
	for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(),a.end(),cmp);
	reverse (a.begin(),a.end());
	for(int i=0;i<n;i++){
		auto p=upper_bound(f.begin(),f.end(),a[i]);
		if(p==f.end()) f.push_back(a[i]);
		else *p=a[i];
	}
	cout << f.size();
}

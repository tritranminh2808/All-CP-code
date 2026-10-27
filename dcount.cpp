#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int, int > a , pair <int,int> b){
	return a.second> b.second;
}
int main(){
	int n; cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	vector <pair <int, int > > v;
	v.push_back({a[0],1});
	for(int i=1;i<n;i++){
		if(a[i]==v[v.size()-1].first) v[v.size()-1].second++;
		else v.push_back({a[i],1});
	}
	cout << v.size() << " ";
	sort(v.begin(),v.end(),cmp);
	cout << v[0].second;
	return 0;
}

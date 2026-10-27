#include <bits/stdc++.h>
using namespace std;
bool cmp( pair <int, int > a, pair <int, int > b){
	return a.first <b.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <pair <int, int > > v;
		for(int i=0;i<n;i++) {
			int a; cin >> a;
			v.push_back({a,i});
		}
		sort(v.begin(),v.end(),cmp);
		vector <int> v2,v3;
		int i=0,j=n-1;
		while(v[i].first==v[0].first){
			v2.push_back(v[i].second);
			i++;
		}
		while(v[j].first==v[n-1].first){
			v3.push_back(v[j].second);
			j--;
		}int sol=1e8;
		sort(v2.begin(),v2.end());
		sort(v3.begin(),v3.end());
		for(auto ii:v2){
			for(auto jj:v3) sol=min(sol,abs(ii-jj)+1);
		}
		cout << sol << "\n";
	}
	return 0;
}

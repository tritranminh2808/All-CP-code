#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int, int > a,pair < int,int> b){
	return a.second<b.second;
}
signed main(){
	freopen("badminton.inp","r",stdin);
	freopen("badminton.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,ind=0,sol=0; cin >> n; 
	vector <pair < int, int > > v(n),v1(n);
	for(int i=0;i<n;i++)cin >> v[i].first >> v[i].second;
	for(int i=0;i<n;i++)cin >> v1[i].first >> v1[i].second;
	sort(v.begin(),v.end(),cmp);
	sort(v1.begin(),v1.end(),cmp);
	multiset<int> S;
	for(int i=0;i<n;i++){
		int l=v[i].first, r=v[i].second;
		while(v1[ind].second<r&&ind<n){
			S.insert(v1[ind].first);
			ind++;
		}
		auto it=S.lower_bound(l);
		if(it!=S.begin()){
			auto k=prev(it);
			S.erase(k);
			sol++;
		}
	}
	cout << sol;
	return 0;
}

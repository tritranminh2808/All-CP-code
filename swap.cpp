#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;int b[1000005];
int sech[1000005];
bool cmp(pair <int, int > a, pair <int, int > b){
	return a.first < b.first;
}
int sol=92839721837211;
signed main(){
	cin >> n>>k;
	vector <pair<int, int > > a(n+1);
	for(int i=1;i<=n;i++) {
		cin >> a[i].first;
		a[i].second=i;
	}
	sort(a.begin()+k+1,a.end(),cmp);
	sech[n+1]=9999999999999;
	for(int i=n;i>=k+1;i--) sech[i]=min(sech[i+1],a[i].second);
//	for(auto i : a) cout << i.first << " ";
	for(int i=1;i<=k;i++){
		pair <int,int> x={a[i].first,(int)99999999999};
		auto it=upper_bound(a.begin()+k+1,a.end(),x)-a.begin();
		sol=min(sol,sech[it]-i);
	}
	cout << sol;
	return 0;
}

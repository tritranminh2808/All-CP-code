#include <bits/stdc++.h>
using namespace std;
bool cmp( pair <long long ,long long> a, pair <long long ,long long > b){
	return a.second*b.first > b.second*a.first;
}
long long sol=0;
int main(){
	long long n,k; cin >> n >> k;
	vector < pair < long long , long long > > v(n);
	for(long long i=0;i<n;i++) cin >> v[i].first >> v[i].second;
	sort (v.begin(),v.end(),cmp);
	for(long long i=0;i<n;i++) {
		if(k>=v[i].first){
			sol+=v[i].second;
			k-=v[i].first;
		}
	}
	cout << sol;
	return 0;
}

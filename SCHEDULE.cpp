#include <bits/stdc++.h>
using namespace std;
bool cmp( pair < long long , long long > a, pair < long long ,long long > b){
	return (float)a.first/a.second>(float)b.first/b.second;
}
long long a[(const int)1e5+5],b[(const int)1e5+5];
long long n; 
long long sol=0;
int main(){
	cin >> n;
	
	for(long long i=0;i<n;i++) cin >> a[i];
	for(long long i=0;i<n;i++) cin >> b[i];
	vector < pair < long long , long long > > v(n);
	for(long long i=0;i<n;i++) {
		v[i].first=a[i];
		v[i].second=b[i];
	}
	sort(v.begin(),v.end(),cmp);
	sol+=v[0].first*v[0].second;
	for(long long i=1;i<n;i++) {
		v[i].second+=v[i-1].second;
		sol+=v[i].first*v[i].second;
	}
	cout << sol;
	return 0;
}

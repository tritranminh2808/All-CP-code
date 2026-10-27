#include <bits/stdc++.h>
//#define int long long
using namespace std;

int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
double c=0;
bool cmp(pair <int, int > a, pair <int, int > b){
	return a.first-a.second*c>b.first-c*b.second;
}
signed main(){
	int n,k; cin >> n >> k;
	vector <pair <int, int > > v(n);
	for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
	double l=0,r=0;
	for(int i=0;i<n;i++) r=max(r,(double)v[i].first/v[i].second);
	int xx=80;
	while(xx--){
		double mid=(l+r)/2;
		c=mid;
		sort(v.begin(),v.end(),cmp); 
		long double check=0;
		for(int i=0;i<k;i++) check+=v[i].first-mid*v[i].second;
		if(check>=0) l=mid;
		else r=mid; 
	}
	c=l;
	sort(v.begin(),v.end(),cmp);
	long long ts=0,ms=0;
	for(int i=0;i<k;i++){
		ts+=v[i].first;
		ms+=v[i].second;
	}
	long long g=__gcd(ts,ms);
	cout << ts/g << " " << ms/g;
	return 0;
}

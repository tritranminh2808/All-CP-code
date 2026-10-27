#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
using namespace std;
int n;
bool cmp( pair <int, int > a, pair < int, int > b)
{
	if(a.second-a.first!=b.second-b.first) return a.second-a.first < b.second-b.first;
	return a.first>b.first;
}
int sol=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector < pair < int , int > > v(2*n);
	for(int i=0;i<n*2;i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(),v.end(),cmp);
	bool check=0;
	for(int i=0;i<n;i++) sol+=v[i].second;
	for(int i=n;i<2*n;i++) sol+=v[i].first;
	cout << sol;
	return 0;
}

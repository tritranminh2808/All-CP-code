#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,k; cin >> n >> k;
	vector <int> v;
	for(int i=0;i<n;i++){
		int x; cin >> x;
		v.push_back(x);
	}
	int sol=1e18;
	for(auto x:v){
		int s=0;
		for(int i=0;i<v.size();i++){
			if(v[i]<x) s+=min(v[i]+k-x,x-v[i]);
			else s+=min(v[i]-x,k+x-v[i]);
		}
		//cout<< s <<endl;
		sol=min(sol,s);
	}
	cout << sol;
	return 0;
}

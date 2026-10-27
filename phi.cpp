#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin >> n;
	int sol=n;
	vector <int> v;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) v.push_back(i);
		while(n%i==0)n/=i;
	}
	if(n!=1) v.push_back(n);
	
	for(auto i : v){
		sol*=(i-1);
		sol/=i;
	}
	cout << sol;
	
	return 0;
}

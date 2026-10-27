#include <bits/stdc++.h>
using namespace std;
bool check(int n, int k){
	if(n>=6) return false;
	int f=1; for(int i=2;i<=n;i++) f*=i;
	if(k*f%9==0) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n,k; cin >> n >> k;
		vector <int> v;
		v.push_back(1);
		if(k%3==0||n>=3) v.push_back(3);
		if(k==5) v.push_back(5);
		if(n>=3||k==7) v.push_back(7);
		if(k==9||n>=6||check(n,k))v.push_back(9);
		for(auto i : v) cout << i << " ";
		cout << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
	while(q--){
		int a; cin >> a;
		vector <int> v;
		long long sol=a-1;
		for(int i=2;i<=sqrt(a);i++) {
			if(a%i==0) v.push_back(i);
			v.push_back(a/i);
		}
		sort(v.begin(),v.end());
		for(auto i : v) sol=max(sol,(long long)(a-i)*__gcd(a-i,a));
		
		cout << sol << "\n";
	}
	return 0;
}

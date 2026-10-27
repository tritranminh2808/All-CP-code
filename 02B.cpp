#include <bits/stdc++.h>
using ll=long long;
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	map< ll,int> mp;
	ll s=0;
	for(int i=0;i<n;i++){
		ll x; cin >> x;
		s^=x;
	}
	cout << s;
}

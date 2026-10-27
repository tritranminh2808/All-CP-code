#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n,k ; cin >> n >> k;
	vector <int> a(n);
	for(int i=0;i<n;i++) {
		cin>> a[i];
		a[i]%=k;
	}
	unordered_map<int,int> mp;
	int sol=0;
	for(int i=0;i<n;i++){
		sol+=mp[0-a[i]];
		sol+=mp[-k-a[i]];
		sol+=mp[k-a[i]];
		mp[a[i]]++;
	}
	cout << sol;
	return 0; 
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int sol=0;
signed main(){
	int n; cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		sol+=a[i]%mod*a[i]%mod;
	}
	int sum=0;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		sol+=sum*a[i]%mod;
		sum=sum*2%mod+a[i]%mod;
	}
	cout << sol%mod;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[(const int) 1e6+5];
int sol=1;
const int mod=1e9+7;
signed main(){
	int n; cin>> n;
	string s;
	cin >> s;
	int k=s.length();
	for(int i=0;i<n-k;i++) sol*=26%mod;
	cout << sol*2;
	return 0;
}

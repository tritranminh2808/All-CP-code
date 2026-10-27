#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e6+5;
int a[p],s[p];
int n,t;

signed main(){
	int n,k; cin >> n>>k;
	vector <int> v(n+1);
	vector <int> f(n+1);
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		f[i]=f[i-1]+a[i];
	}
	int t=f[0];
	
	int sol=-1e18;
	for(int i=k;i<=n;i++) {
		sol=max(sol,f[i]-t);
		t=min(t,f[i-k+1]);
	}
	cout << sol << "\n";
}

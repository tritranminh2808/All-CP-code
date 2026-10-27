#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[(1<<21)+1];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m; cin >> m;
	int n=__lg(m);
	vector <int> a(m+1);
	for(int i=1;i<=m;i++) {
		cin >> a[i];
		f[i]=a[i];
	}
	for(int i=0;i<=n;i++){
		for(int mask=0;mask<(1<<(n+1));++mask){
			if((mask>>i)&1) f[mask]+=f[mask-(1<<i)];
		}
	}
	for(int i=1;i<(1<<(n+1));++i) cout << f[i] << " ";
	return 0;
}

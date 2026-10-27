#include <bits/stdc++.h>
//#define int long long
using namespace std;
int a[1000005],b[1000005],t[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n >> m;
	long long s=0;
	for(int i=1;i<=m;i++) {
		cin >> a[i] >> b[i] >> t[i];
		s+=t[i];
	}
	cout << s*2;
	return 0;
}

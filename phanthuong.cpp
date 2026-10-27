#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int a[1000005],suf[1000005];
signed main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	vector <int> v;
	for(int i=n;i>=1;--i) {
		suf[i]=suf[i+1]+a[i];
		v.push_back(suf[i]);
	}
	int s=0,res=-1000000000000000005;
	int ind=0;
	for(int i=0;i<n;i++){
		if(s>=v[i]+s-ind) ind=v[i];
		else s=s+v[i]-ind;
		res=max(res,s);
	}
	cout << res;
	return 0;
}

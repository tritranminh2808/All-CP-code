#include <bits/stdc++.h>
#define int long long
using namespace std;
const int pp=1e7+1;
long long v[pp],pre[pp],suf[pp];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k; cin >> n >> k;
	long long x,a,b,c;
	cin >> x >> a >> b >> c;
	v[1]=x;
	for(int i=2;i<=n;i++) v[i]=(a*v[i-1]%c+b)%c;
	pre[1]=x;
	for(int i=2;i<=n;i++) {
		if(i%k==1) pre[i]=v[i];
		else pre[i]=pre[i-1]|v[i];
	}
	suf[n]=v[n];
	for(int i=n-1;i>=1;i--) {
		if(i%k==0) suf[i]=v[i];
		else suf[i]=suf[i+1]|v[i];
	}
	long long sol=0;
	int l=1,r=k;
//	for(int i=1;i<=n;i++) cout << suf[i] << " ";
	while(r<=n){
		if(r%k==0) sol^=pre[r];
		else sol^=(pre[r]|suf[l]);
//		cout << sol << ' ' << r << '\n';
		r++;
		l++;
	}
	cout << sol;
	return 0;
}	

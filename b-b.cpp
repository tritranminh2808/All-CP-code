#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, mod2=1e9+9;
using ull=unsigned long long;
int power[1000005],power2[1000005],hashP[1000005],hashP2[1000005];
int a[1000005],b[1000005],x[1000005],y[1000005];
int sol=0;
signed main(){
	int n,m; cin >> n >>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int j=1;j<=m;j++) cin >> b[j];
	for(int i=1;i<n;i++) x[i]=a[i+1]-a[i]+1000006;
	for(int i=1;i<m;i++) y[i]=b[i+1]-b[i]+1000006;
	const int c=1000003,c2=10000033;
	power[0] = 1;
	power2[0]=1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	for(int i = 1; i <= 1e6; i++) power2[i] = power2[i - 1] * c2 % mod2;
//	int t ; cin >> t;
	int hbase=0,hbase2=0;
	for(int i=1;i<m;i++) {
		hbase=(hbase*c+y[i]+1)%mod;
		hbase2=(hbase2*c2+y[i]+1)%mod2;
	}
	for(int i=1;i<n;i++){
		hashP[i]=(hashP[i-1]*c+x[i]+1)%mod;
		hashP2[i]=(hashP2[i-1]*c2+x[i]+1)%mod2;
	}
	for(int i=m-1;i<n;i++) {
		int k=(hashP[i]-hashP[i-m+1]*power[m-1])%mod;
//		int k2=(hashP2[i]-hashP2[i-m+1]*power2[m-1])%mod2;
		if(k<0)k+=mod;
//		if(k2<0) k2+=mod2;
		if(k==hbase/*&&k2==hbase2*/) sol++;
	}
	cout << sol;
	return 0;
}


#include <bits/stdc++.h>
#define int long long
using namespace std;
int power[100005];
const int mod=1e9+7,base=1000003,base2=1000033, mod2=1e9+9;
int hasht[100005],a[100005], f[100005],power2[100005],hash2[100005];
bool check(int x, int n){
	unordered_map<int, bool> mp,mp2;
	for(int i=1;i<=n-x;i++){
		int k=(hasht[i+x-1]- hasht[i-1]*power[x])%mod;
		if(k<0) k+=mod;
		int k2=(hash2[i+x-1]- hash2[i-1]*power2[x])%mod2;
		if(k2<0) k2+=mod2;
		if(mp[k]==1&&mp2[k2]==1) return true;
		mp[k]=1;
		mp2[k2]=1;
	}
	return false;
}
signed main(){
	power[0]=1;
	for(int i=1;i<=100000;i++) power[i]=power[i-1]*base%mod;
	power2[0]=1;
	for(int i=1;i<=100000;i++) power2[i]=power2[i-1]*base2%mod2;
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		for(int i=0;i<=n;i++) {
			hasht[i]=0;
			hash2[i]=0;
			a[i]=0;
			f[i]=0;
		}
		for(int i=1;i<=n;i++) cin >> a[i];
		int minn=0;
		for(int i=1;i<n;i++) {
			f[i]=a[i+1]-a[i];
			minn=min(minn,f[i]);
		}
		for(int i=1;i<n;i++) {
			hasht[i]=(hasht[i-1]*base+f[i]+1)%mod;
			hash2[i]=(hash2[i-1]*base2+f[i]+1)%mod2;
		}
		int l=1,r=(n-1)/2;
		while (l<=r){
			int mid=(l+r)/2;
			if(check(mid,n)) l=mid+1;
			else r=mid-1;
		}
		cout << l << "\n";
	}
}

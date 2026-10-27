#include <bits/stdc++.h>
#define int long long
using namespace std;
long long dp[200005],a[200005];
int n;
void cok(){
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		dp[i]=a[i]%100;
		for(int j=1;j<i;j++){
			if(a[j]<a[i]) dp[i]=max(dp[i],a[i]%100+dp[j]);
		}
	}
	long long sol=0;
	for(int i=1;i<=n;i++) sol=max(sol,dp[i]);
	cout << sol;
}
long long st[800005];
void update(int id,int l, int r, int u, long long v){
	if(u>r||l>u) return;
	if(l==r) {
		st[id]=v;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	st[id]=max(st[2*id],st[id*2+1]);
}
long long find(int id, int l, int r, int lf,int rt){
	if(rt<l||lf>r) return -1234567898761;
	if(lf<=l&&rt>=r) return st[id];
	int mid=(l+r)/2;
	int k1=find(2*id,l,mid,lf,rt),k2=find(2*id+1,mid+1,r,lf,rt);
	return max(k1,k2);
}
long long find2(int id, int l, int r, int u){
	if(u<l||u>r) return -1234567898761;
	if(l==r) return st[id];
	int mid=(l+r)/2;
	int k1=find2(2*id,l,mid,u),k2=find2(2*id+1,mid+1,r,u);
	return max(k1,k2);
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("mis.inp","r",stdin);
//	freopen("mis.out","w",stdout);
	for(int i=0;i<=800000;i++) st[i]=-1234567898761;
	cin >> n;
	if(n<=5000){
		cok();
		return 0;
	}
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		dp[i]=a[i]%100;
		int maxx=0;
		int qq=find(1,1,100000,1,a[i]-1);
		maxx=max(maxx,qq);
		dp[i]+=maxx;
		int pp=find2(1,1,100000,a[i]);
		if(dp[i]>pp) update(1,1,100000,a[i],dp[i]);
	}
	int sol=0;
	for(int i=1;i<=n;++i) sol=max(sol,dp[i]);
	cout << sol;
	return 0;
}

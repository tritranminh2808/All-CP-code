#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005], st[1000005],dp[100005];
void update(int id, int l, int r, int u, int v){
	if(l>u||r<u) return;
	if(l==r) {
		st[id]=v;
		return ;
	}
	int mid=(l+r)/2;
	update(2*id,l,mid,u,v);
	update(2*id+1,mid+1,r,u,v);
	st[id]=max(st[id*2],st[id*2+1]);
}
int find(int id, int l, int r, int x, int y){
	if(x>r||y<l) return 0;
	if(x<=l&&y>=r) return st[id];
	int mid=(r+l)/2;
	int i=find(2*id,l,mid,x,y);
	int j=find(2*id+1,mid+1,r,x,y);
	return max(i,j);
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k; cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		dp[i]=find(1,1,n,max((int)0,i-k),i-1)+a[i];
		update(1,1,n,i,dp[i]);
	}
	long long sol=0;
	for(int i=1;i<=n;i++) sol=max(sol,dp[i]);
	cout << sol;
	return 0;
}

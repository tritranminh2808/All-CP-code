#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int inf = -1e16;
int a[50005];
struct pl{
	int maxx,sum,pre,suf;
};
pl st[400005];
pl merge(pl x, pl y){
	pl c;
	c.sum=x.sum+y.sum;
	c.pre=max(x.pre,x.sum+y.pre);
	c.suf=max(y.suf,y.sum+x.suf);
	c.maxx=max({x.maxx,y.maxx,x.suf+y.pre});
	return c;
}
void build(int id, int l, int r){
//	cout << id << " ";
	if(l==r){
		st[id]={a[l],a[l],a[l],a[l]};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
pl find(int id, int l, int r, int lf, int rt){
	if(lf>r||rt<l) return {inf,0,inf,inf};
	if(lf<=l&&rt>=r) return st[id];
	int mid=(l+r)/2;
	return merge(find(id*2,l,mid,lf,rt),find(id*2+1,mid+1,r,lf,rt));
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<=400000;i++){
		st[i].maxx=inf;
		st[i].pre=inf;
		st[i].suf=inf;
	}
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
//	cout << 0;
	int q; cin >> q;
	while(q--){
		int l,r; cin >> l >> r;
		cout << find(1,1,n,l,r).maxx << "\n";
	}
	return 0;
}
